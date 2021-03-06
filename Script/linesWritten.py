# linesWritten.py
# Returns how many lines of code exist in it's path.

'''
A replacement for this program is:
wc -l $(git ls-files)
'''

import common

def main():
	lines = 0
	for filename in common.getFiles(common.isValidCode):
		lines += lengthOf(filename)
	print("%d lines of code were found" % lines)
 
def lengthOf(filename):
	try:
		return sum(1 for line in open(filename))
	except:
		print("There was an error and %s could not be read" % filename)
		return 0
	
main()