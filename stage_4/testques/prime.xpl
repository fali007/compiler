decl
	int n,i,j;
enddecl
begin
	read(n);
	j=0;
	if((n%2)==0) then
		j=1;
	else
		i=3;
		while(i<=(n/2)) do
			if((n%i)==0) then
				j=1;
			endif;
			i=i+2;
		endwhile;
	endif;
	if(j==0) then
		write("Prime");
	else write("Not Prime");
	endif;
    end;
