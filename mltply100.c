int main(int argc, char* argv[])
{
	int a = 41;
	char *p,*c,*temp,*t;
	p = malloc(sizeof(char) * 10);
	c = p;

	//Convert the int to String
	int temp = a%10;
	while(temp != 0)
	{
		*p = (char)(48 + temp);
		p++;
	        a = a / 10;
		temp = a %10;
	} 


	//Reverse the string
	temp = malloc(sizeof(char) *10);
	t = temp;
	while(p != c)
        {
		*temp = *p;
		p--;
		temp++;
		if (p == c){
			*temp = *p; temp++;}
	}		

	
        //Now temp is having original number in char format, append 2 zeros to this number
	*temp='0';
	temp++; *temp = '0';
	
	//Now get to the start of the *temp and print the string
	
        while(temp != t)
	{
		temp --;
	}

	printf("%s", temp);		
	
		
	return 0;	
}
