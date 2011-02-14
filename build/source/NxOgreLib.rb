require 'ffi'

module NxOgreLib

	extend FFI::Library
	ffi_lib 'NxOgreDebug.dll'
	ffi_convention :stdcall

	attach_function 'NXC_WorldCreate', [:pointer], :pointer
	attach_function 'NXC_WorldDestroy', [], :void
	attach_function 'NXC_WorldAdvance', [:pointer, :float], :void
	attach_function 'NXC_WorldSetAssertionPolicy', [:pointer, :int], :void
	attach_function 'NXC_WorldGetAssertionPolicy', [:pointer], :int
	attach_function 'NXC_WorldDescriptionNew', [], :pointer
	attach_function 'NXC_WorldDescriptionReset', [:pointer], :void
	attach_function 'NXC_WorldDescriptionDelete', [:pointer], :void

	class Enums
	 PHYSXASSERTIONPOLICY_CONTINUE = 0
	 PHYSXASSERTIONPOLICY_IGNORE = 1
     PHYSXASSERTIONPOLICY_BREAKPOINT = 2
	 PHYSXASSERTIONPOLICY_EXCEPTION = 3
	end

	class WorldDescription < FFI::Struct
		  layout  	:assertion_policy, :int,
		  			:cooker_thread_mask, :uint,
		  			:hardware_maximum_convex, :uint,
		  			:hardware_page_size, :uint, 
		  			:hardware_maximum_page, :uint,
		  	 		:no_hardware, :int,
		  			:per_scene_batching, :int,
		  			:gpu_heap_size, :uint, 
		  			:mesh_cache_size, :uint
		  def initialize
			self[:assertion_policy] = Enums::PHYSXASSERTIONPOLICY_CONTINUE
			self[:cooker_thread_mask] = 0
			self[:gpu_heap_size] = 32
			self[:hardware_maximum_convex] = 2048
			self[:hardware_maximum_page] = 256
			self[:hardware_page_size] = 65536
			self[:mesh_cache_size] = 0xffffffff
			self[:no_hardware] = 1
			self[:per_scene_batching] = 1
		  end
	end

	class World

		def self.createWorld!(world_desc)
			@@singleton = World.new(world_desc)
			return @@singleton
		end

		def self.destroyWorld!
			@@singleton.shutdown
		end

		def self.instance
			return @@singleton
		end

		def advance(deltaTime = 0.16667)
			NxOgreLib.NXC_WorldAdvance(@world, deltaTime.to_f)
		end

		def initialize(world_desc)
			@world = NxOgreLib.NXC_WorldCreate(world_desc)
		end

		def shutdown
			NxOgreLib.NXC_WorldDestroy
		end

		def setAssertionPolicy(policy)
			if policy == :continue
				NxOgreLib.NXC_WorldSetAssertionPolicy(@world, Enums::PHYSXASSERTIONPOLICY_CONTINUE)
			elsif policy == :ignore
				NxOgreLib.NXC_WorldSetAssertionPolicy(@world, Enums::PHYSXASSERTIONPOLICY_IGNORE)
			elsif policy == :breakpoint
				NxOgreLib.NXC_WorldSetAssertionPolicy(@world, Enums::PHYSXASSERTIONPOLICY_BREAKPOINT)
			elsif policy == :exception
				NxOgreLib.NXC_WorldSetAssertionPolicy(@world, Enums::PHYSXASSERTIONPOLICY_EXCEPTION)
			end
		end


		def getAssertionPolicy()
			policy = NxOgreLib.NXC_WorldGetAssertionPolicy(@world)
			if policy == Enums::PHYSXASSERTIONPOLICY_CONTINUE
				return :continue
			elsif policy == Enums::PHYSXASSERTIONPOLICY_IGNORE
				return :ignore
			elsif policy == Enums::PHYSXASSERTIONPOLICY_BREAKPOINT
				return :breakpoint
			elsif policy == :exception
				return :exception
			end
			return :continue
		end
		
	end

end
