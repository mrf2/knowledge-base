char *func() 
{
	static char buf[32];
	buf[0] = 'A';
	
	return buf;
}

