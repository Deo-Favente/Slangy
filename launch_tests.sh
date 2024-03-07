make 
echo "TESTS CORRECTS"
echo "-----------------------------------"
for file in Tests/Corrects/*.txt
do
    if [ -f "$file" ] 
        then
            echo "Running calculette on $file (should pass)"
            ./calculette $file
            echo "-----------------------------------"
        fi
done
echo "TESTS INCORRECTS"
echo "-----------------------------------"
for file in Tests/Incorrects/*.txt
do
    if [ -f "$file" ] 
        then
            echo "Running calculette on $file (should not pass)"
            ./calculette $file
            echo "-----------------------------------"
        fi
done
make clean