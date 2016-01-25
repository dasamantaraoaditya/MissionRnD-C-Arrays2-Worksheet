/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/
#define NULL 0
int findSingleOccurenceNumber(int *A, int len) {
	if (A == NULL|| len < 0)
		return -1;
	int i, j, unique[100][2] = { { 0 }, { 0 } }, k = 0, flag;
	for (i = 0; i < len; i++){
		for (j = 0; j <k; j++){
			flag = 1;
			if (unique[j][0] == A[i])
			{
				unique[j][1]++;
				flag = 0;
				break;
			}
		}
		if (flag)
			unique[k++][0] = A[i];
	}
	for (i = 0; i < k; i++)
		if (unique[i][1] == 0)
			return unique[i][0];
	return -1;
}