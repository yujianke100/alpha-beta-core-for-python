# alpha-beta-core-for-python

Original project: https://github.com/boge-liu/alpha-beta-core

## Install Environment

`pip install pybind11`

**If you can use sudo:**

`sudo apt-get -y install libboost-all-dev`

**Or use conda:**

`conda install -c conda-forge boost`

## Build

`bash build.sh`

Now, you can `import pyabcore` and use it as test.py. Ensure pyabcore.*.so (linux) or pyabcore.*.pyd (windows) file is in the same folder as your Python script.