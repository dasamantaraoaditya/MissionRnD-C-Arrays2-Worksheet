/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int isOlder(char *dob1, char *dob2);
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == '\0' || ALen < 0 || B == '\0' || BLen < 0)
		return '\0';
	int max = ALen > BLen ? ALen : BLen;
	struct transaction *op,*org;
	op = (struct transaction *)malloc(sizeof(struct transaction)*max);

	int i = 0, j = 0, k = 0,count=0;
	while (i<ALen&&j<BLen){
		int old = isOlder(A[i].date, B[j].date);
		if (old == 2)
		{
			//op[k].amount=B[j].amount;//add B
			//op[k].date=B[j].date;
			//op[k].description=B[j].description;
			j++;
		}
		else if (old == 1)
		{
			//op[k].amount=A[i].amount;//add A
			i++;
		}
		else
		{
			op[k++].amount = B[j].amount;
			i++; j++;
			count++;
		}

	}
	if (count==0)
		op = NULL;
	return op;
}/*
int isOlder(char *dob1, char *dob2) {
	int i = 0, dd1 = 0, mm1 = 0, yyyy1 = 0, dd2 = 0, mm2 = 0, yyyy2 = 0;
	while (dob1[i] != '-'&&dob1[i] != '\0')
	{
		if (dob1[i] < '0' || dob1[i] > '9')
			return -1;
		dd1 *= 10;
		dd1 += dob1[i] - '0';
		i++;
	}
	if (dob1[i] == '\0')
		return -1;
	i++;

	while (dob1[i] != '-'&&dob1[i] != '\0')
	{
		if (dob1[i] < '0' || dob1[i] > '9')
			return -1;
		mm1 *= 10;
		mm1 += dob1[i] - '0';
		i++;
	}

	if (dob1[i] == '\0')
		return -1;
	i++;

	while (dob1[i] != '-'&&dob1[i] != '\0')
	{
		if (dob1[i] < '0' || dob1[i] > '9')
			return -1;
		yyyy1 *= 10;
		yyyy1 += dob1[i] - '0';
		i++;
	}

	if (dob1[i] == '\0')
	{
		if (yyyy1 % 4 == 0 && mm1 == 2 && dd1 >= 30)
			return -1;
		if (yyyy1 % 4 != 0 && mm1 == 2 && dd1 >= 29)
			return -1;
		if (mm1 > 12 || dd1 > 31)
			return -1;
	}
	else
		return -1;

	i = 0;

	while (dob2[i] != '-'&&dob2[i] != '\0')
	{
		if (dob2[i] < '0' || dob2[i] > '9')
			return -1;
		dd2 *= 10;
		dd2 += dob2[i] - '0';
		i++;
	}
	if (dob2[i] == '\0')
		return -1;
	i++;
	while (dob2[i] != '-'&&dob2[i] != '\0')
	{
		if (dob2[i] < '0' || dob2[i] > '9')
			return -1;
		mm2 *= 10;
		mm2 += dob2[i] - '0';

		i++;
	}
	if (dob2[i] == '\0')
		return -1;
	i++;
	while (dob2[i] != '-'&&dob2[i] != '\0')
	{
		if (dob2[i] < '0' || dob2[i] > '9')
			return -1;
		yyyy2 *= 10;
		yyyy2 += dob2[i] - '0';
		i++;
	}
	if (dob2[i] == '\0')
	{
		if (yyyy2 % 4 == 0 && mm2 == 2 && dd2 >= 30)
			return -1;
		if (yyyy2 % 4 != 0 && mm2 == 2 && dd2 >= 29)
			return -1;
		if (mm2 > 12 || dd2 > 31)
			return -1;
	}
	else
		return -1;

	if (yyyy1>yyyy2)
		return 2;
	else if (yyyy1<yyyy2)
		return 1;
	else
	{
		if (mm1>mm2)
			return 2;
		else if (mm1<mm2)
			return 1;
		else
		{
			if (dd1>dd2)
				return 2;
			else if (dd1<dd2)
				return 1;
			else
				return 0;
		}
	}
	return 0;
}
*/