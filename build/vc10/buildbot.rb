# Build Bot
# Version 1.1
# ====================================

require 'YAML'
require 'rubygems'
require 'webster'
require 'fileutils'
require 'digest/md5'

PREFS = YAML::load(DATA)

if (File.exists?('../.developer') == false)
	puts "This is not a developer SDK. I will not run."
	Process.exit
end

def escape_if(cond, reason = nil)
	if (cond)
		puts "[BuildBot] #{reason}" if reason != nil
		Process.exit
	end
end

def comment(line)
	puts "[BuildBot] #{line}"
end

def do_version(args)
	escape_if PREFS["version_file"] == nil, "Version file not given in configuration"
	f = File.read(PREFS["version_file"])
	escape_if f == nil, "Could not find or read file"
	prefix = (PREFS["project"] || "Project")

	hsh = nil
	mhsh = nil
	# Try and fetch hash
	res = f.scan /\/\/~~\s+mtime\s+(\w+)/
	if res[0] != nil
		hsh = res[0][0].downcase.strip if res[0][0] != nil
	end

	mdates = Array.new
	Dir.glob(PREFS["cpp_files"]).each do |fn|
		next if (File.basename(fn) == File.basename(PREFS["unity_build_file"]) )
		mdates.push File.stat(fn).mtime.to_i.to_s
	end
	Dir.glob(PREFS["h_files"]).each do |fn|
		next if (File.basename(fn) == File.basename(PREFS["version_file"]) )
		mdates.push File.stat(fn).mtime.to_i.to_s
	end
	mhsh = Digest::MD5.hexdigest(mdates.join(',')).downcase

	return if hsh == mhsh
	
	###########

	# Bump build number.
	f.gsub! /^\s*#define\s+#{prefix}VersionBuild\s+\d+/ do |ln|
		build = ln.scan(/Build\s+(\d+)/)[0][0]
		ln.gsub(build.to_s, (build.to_i + 1).to_s)
	end
	
	# Bump build name
	webster = Webster.new
	build_name = webster.random_word.capitalize

	f.gsub! /^\s*#define\s+NxOgreBuildName\s+"\w+"/ do |ln|
		ln.gsub(/\"\w+\"/, "\"#{build_name}\"")
	end

	# Bump modified time
	f.gsub! /^\s*\/\/~~\s+mtime\s+\w+/ do |ln|
		ln.gsub(/mtime\s+\w+/, "mtime " + mhsh)
	end


	File.open(PREFS["version_file"], 'w')  { |c| c.write f }
	
	comment "This is build '#{build_name}'"
end

def do_unitybuild(args)
	escape_if PREFS["cpp_files"] == nil, "No .cpp files given in the configuration"
	escape_if PREFS["unity_build_file"] == nil, "No Unity Build file given in the configuration"

	f = File.read(PREFS["unity_build_file"])

	refreshRequired = false
	hsh = nil
	mhsh = nil
	# Try and fetch hash
	res = f.scan /\/\/~~\s+ub_begin\s+(\w+)/
	if res[0] != nil
		hsh = res[0][0].downcase.strip if res[0][0] != nil
	end

	# Compare hash with generated hash of the cpp file modified dates
	# If there is no hash, then a refresh is required anyway, as the file is new.
	if hsh != nil
		mdates = Array.new
		Dir.glob(PREFS["cpp_files"]).each do |fn|
			mdates.push File.stat(fn).mtime.to_i.to_s
		end
		mhsh = Digest::MD5.hexdigest(mdates.join(',')).downcase
		refreshRequired = true if mhsh != hsh
	else
		refreshRequired = true
	end
	
	if refreshRequired
		
		escape_if((f.scan(/\/\/~~\s+ub_begin/)[0] == nil), "Cannot find '~~ ub_begin comment' in #{PREFS["unity_build_file"]}")
		escape_if((f.scan(/\/\/~~\s+ub_end/)[0] == nil), "Cannot find '~~ ub_end comment' #{PREFS["unity_build_file"]}")
		
		if (mhsh == nil)
			mdates = Array.new
			Dir.glob(PREFS["cpp_files"]).each do |fn|
				mdates.push File.stat(fn).mtime.to_i.to_s
			end
			mhsh = Digest::MD5.hexdigest(mdates.join(',')).downcase
		end

		cpp = String.new
		cpp << "//~~ ub_begin #{mhsh}\n\n"

		Dir.glob(PREFS["cpp_files"]).each do |fn|
			cpp << "#include \"#{File.basename(fn)}\"\n"
		end
		cpp << "\n//~~ ub_end\n"
		f.gsub! /(^\s*\/\/~~\s+ub_begin.*^\s*\/\/~~\s+ub_end)\n/m, cpp
		
		File.open(PREFS["unity_build_file"], 'w')  { |c| c.write f }

		comment "Changes made to source files. Generating new UnityBuild file."
	end
end

escape_if ARGV.size == 0, "Wrong number of arguments given"

string_args = ARGV.join(',')
main_args = string_args.split('and')

main_args.each do |a|
	args = a.split(',')
	args.delete(String.new)
	tool = args[0].downcase
	args.delete(0)

	do_version(args) if tool == 'version'
	do_unitybuild(args) if tool == 'unitybuild'

end

__END__

# Configuration (as YAML)
version_file: ../source/NxOgreVersion.h
cpp_files:
  - ../source/NxOgre*.cpp
h_files:
  - ../source/*.h
unity_build_file: ../source/__NxOgre_UnityBuild.cpp
project: NxOgre