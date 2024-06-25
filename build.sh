# build.sh
# sudo apt install swig or conda install swig
# if boost is not installed: sudo apt-get -y install libboost-all-dev or conda install -c conda-forge boost
cd src
if [ -d "build" ]; then
    rm -r build
fi
swig -c\+\+ -python pyabcore.i
python setup.py build_ext --inplace
cd ..
cp ./src/_pyabcore* ./src/pyabcore.py ./
python test.py