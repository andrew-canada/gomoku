#include <stdio.h>

int main()
{
	int antennas, eyes;
	scanf("%d%d", &antennas, &eyes);

	if (antennas >= 3 && eyes <= 4)
	{
		puts("TroyMartian\n");
	}
	if (antennas <= 6 && eyes >= 2)
	{
		puts("VladSaturnian\n");
	}
	if (antennas <= 2 && eyes <= 3)
	{
		puts("GraemeMercurian\n");
	}
}
