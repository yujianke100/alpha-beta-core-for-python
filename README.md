# alpha-beta-core-for-python

Original project: https://github.com/boge-liu/alpha-beta-core

## Install Environment

install [swig](https://github.com/swig/)

**If you can use sudo:**

`sudo apt-get -y install libboost-all-dev`

`sudo apt install swig`

**Or use conda:**

`conda install swig`

`conda install -c conda-forge boost`

## Build

`bash build.sh`

Now, you can `import pyabcore` and use it as test.py. Ensure _pyabcore.*.so and pyabcore.py is in the same folder as your Python script.