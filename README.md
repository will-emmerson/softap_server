cmake options:
-DIDF_PATH=/home/willemmerson/esp/idf-master 

environment:
IDF_PATH=/home/willemmerson/esp/idf-master;PATH=/home/willemmerson/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin:/home/willemmerson/.espressif/python_env/idf4.3_py3.9_env/bin:/usr/bin

But note that `PATH` will change as the sdk is updated and it depends on your system python version, i.e. the `esp
-2020r3-8.4.0` and `idf4.2_py3.9_env` parts.
