task :default do
  sh 'avr-gcc -mmcu=atmega8 ./main.c -o ./main'
end

task :install => :default do
  sh 'sudo avrdude -c avrispmkII -P usb -p m8 -U flash:w:main:e -v'
end
