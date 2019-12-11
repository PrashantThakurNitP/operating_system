echo "enter"
read string
len1=`echo $string |wc -c`
vowels=$(echo $string|grep -o -i "[a e i o u]" |wc --lines)
echo $len1
echo $vowels
