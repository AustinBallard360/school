p1="Bob"
p2="Joe"
p3="Gregg"
p4="Joe"

#declare -a myList;
declare -a myList
myList+=('foo')
myList+=('baz')
myList+=('bruhhhz')
myList+=('bruhhy')
myList+=('bruhhx')
myList+=('bruh')
myList+=("$p3")
delete=('bruh')

echo "${myList[@]}"


for target in "${delete[@]}"; do
  for i in "${!myList[@]}"; do
    if [[ ${myList[i]} = $target ]]; then
      unset 'myList[i]'
    fi
  done
done
echo "${myList[@]}"

# for i in $myList ; do
# 	echo $i;
# 	echo "i goed"
# done
