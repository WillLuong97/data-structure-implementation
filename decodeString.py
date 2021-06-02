#Given a string with integer and character, return a new string that contains only character as follow: 
'''
input_str = "a2z2b4"
out_str = "aaazzzbbbbb"

int_str = "a1"
out_str = "aa"
'''

#function to solve deocde the given string
def decodeString(input_str):
	#base case: 
	if not input_str or len(input_str) == 0:
		return ""
	#result string to be returned to
	retStr = ""
	str_arr = []
	#convert the original string into a list for eaiser access to the string element
	for char in input_str:
		str_arr.append(char)
	
	#loop through the string array and append the char into a new string based on the number of times a char should exist 
	for i in range(len(input_str)):
		if(input_str[i].isdigit()):
			#for i in range(intinput_str[i])-1):
			#	print(input_str[i-1])
			retStr += input_str[i-1] * int(input_str[i])
		else: 
			retStr += input_str[i]
	return retStr


print(decodeString("a2z2b4"))
print(decodeString("a2"))


