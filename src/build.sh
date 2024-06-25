# build.sh
if [ -d "build" ]; then
    rm -r build
fi
python setup.py build_ext --inplace
python test.py
cp pyabcore.*.so pyabcore.*.pyd ../