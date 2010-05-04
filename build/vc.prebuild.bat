IF NOT EXIST ../bean.rb GOTO NoBean
ruby ../bean.rb
:NoBean

IF NOT EXIST ../source/scones.rb GOTO NoScones
cd ../source/
ruby scones.rb
:NoScones