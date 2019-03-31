decl
int a;
enddecl
begin
a=1;
while(a<10) do
write (a);
a=a+1;
if ( a == 6) then
break;
endif;
endwhile;
end;
