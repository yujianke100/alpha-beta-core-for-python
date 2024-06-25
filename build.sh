# build.sh
# pip install pybind11
# if boost is not installed: conda install -c conda-forge boost
if [ -d "build" ]; then
    rm -r build
fi
cd src
python setup.py build_ext --inplace
cp pyabcore.*.so pyabcore.*.pyd ../
cd ..
python test.py