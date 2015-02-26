What is the output for the following version ofreverse() :
	 void reverse() {
		 int ch;
		 cin.get(ch);
		 if (ch != '\n')
						 reverse();
		 cout.put(ch);
	 }


Programmet looper så længe brugeren indtaster alt andet end <enter>. Når brugeren gør dette printer den alt indputtet baglæns, mens den kommer tilbage gennem "iterationerne"
