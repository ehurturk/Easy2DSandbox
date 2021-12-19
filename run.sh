cd build
if ./Easy2DSandbox ; then
	echo ""
else
	echo "\033[1;31mThere was a problem starting the app...\033[0m"
fi
cd ../