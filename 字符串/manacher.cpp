void manacher {
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=n;i>=1;i--)
		s[i*2]=s[i];
	for(i=1;i<=n*2+1;i+=2)
		s[i]='*';
	s[0]='$';
	m=n*2+1;
	R=pos=0;
	for(i=1;i<=m;i++) {
		if(R<i) {
			p[i]=0;
			for(;s[i+p[i]+1]==s[i-p[i]-1];p[i]++);
			R=p[i]+i;
			pos=i;
			continue;
		}
		j=pos*2-i;
		if(i+p[j]<R) {
			p[i]=p[j];
			continue;
		}
		p[i]=R-i;
		for(;s[i+p[i]+1]==s[i-p[i]-1];p[i]++);
		R=p[i]+i;
		pos=i;
	}
}
