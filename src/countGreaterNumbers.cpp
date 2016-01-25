/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if (Arr == nullptr || len < 0 || date == nullptr)
		return '\0';
	int i, j, great_count = 0, n_dd = 0, n_mm = 0, n_yy = 0;
	for (j = 0; date[j] != '-'; j++)
	{
		n_dd *= 10;
		n_dd += date[j] - '0';
	}
	for (++j; date[j] != '-'; j++)
	{
		n_mm *= 10;
		n_mm += date[j] - '0';
	}
	for (++j; date[j] != '\0'; j++)
	{
		n_yy *= 10;
		n_yy += date[j] - '0';
	}
	for (i = 0; i<len; i++)
	{
		int dd = 0, mm = 0, yy = 0;
		for (j = 0; Arr[i].date[j] != '-'; j++)
		{
			dd *= 10;
			dd += Arr[i].date[j] - '0';
		}
		for (++j; Arr[i].date[j] != '-'; j++)
		{
			mm *= 10;
			mm += Arr[i].date[j] - '0';
		}
		for (++j; Arr[i].date[j] != '\0'; j++)
		{
			yy *= 10;
			yy += Arr[i].date[j] - '0';
		}
		if (n_yy<yy)
		{
			great_count++;
		}
		else if (n_yy == yy)
		{
			if (n_mm<mm)
			{
				great_count++;
			}
			else if (n_mm == mm)
			{
				if (n_dd<dd)
					great_count++;
			}
		}
		//printf("%d%d%d",dd,mm,yy);
	}

	return great_count;
}