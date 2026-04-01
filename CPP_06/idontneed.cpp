/*bool controlType(char c, int n, float fnum, double dnum)
{
	bool flag;
		
	flag = true;
	if(c == 0)
		return (false);
	if(std::isnan(dnum) || std::isinf(dnum)) // nan = not a number, inf = infinito
		flag = false;
	else if(!(isprint(c)) || c < 32 || c > 127)
	{
		flag = false;
		std::cout << "char: Non displayable" << std::endl;
	}
	(void)n;
	(void)fnum;
	(void)dnum;
	return(flag);
	//utiliza el bool para ver si es correcto o no???? necesito una organización del codigo
}*/

/*int controlLength(std::string &str, int &n, float &fnum, double &dnum)
{
	if (!(str.size() > 0 && str.size() < 4))
		return (1);

	n = strtol(str.c_str()); yo no se que coño es esto
	fnum = strtof(str.c_str());
	dnum = strtod(str.c_str());
	
	solo convertir validar en funcion de la longitud
	return(0);
}*/