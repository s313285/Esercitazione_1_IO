#include <fstream>
#include <iostream>
#include <iomanip>

double mappa(double c, int A, int B, int a, int b)
{
	c = (c-A)*(b-a)/(B-A)+a;
	return c;
}

int main()
{
    std::ifstream file("data.txt");
	
	if(file.fail())
	{
		std::cerr << "errore nell'apertura del file" << std::endl;
		return 1;
	}
	
	std::ofstream fout("result.txt");
	
	std::string tmp;   /* tmp=temporaneo */
	std::getline(file, tmp);
	fout << tmp << std::endl;
	
	fout << std::setprecision(16) << std::scientific;
	
	int i=0;
	double val;
	double sum = 0.0;
	while(file >> val)
	{
		i++;
		sum = sum + mappa(val,1,5,-1,2);
		double mean = sum/i;
		fout << i << " " << mean << std::endl;
	}
	file.close();
	fout.close();
	
	return 0;
}
