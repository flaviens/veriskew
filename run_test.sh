export SIMSRAMELF=$PWD/misc/app.elf
export SIMSRAMAUX=$PWD/misc/metadata
fusesoc library add run .
fusesoc run run
