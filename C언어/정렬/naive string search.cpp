#include <stdio.h>
#include <string.h>

int naive_string_search(char * big, char * small){
	int count = 0;
	int answer = 0;
	for(int i=0;i<strlen(big);i++){
		for(int j=0;j<strlen(small);j++){
			if(big[i+j]==small[j]){
				count++;
			}
			
			else if(big[i+j]!=small[j]){
				count=0;
				break;
			}
			
			if(count==strlen(small)){
				count=0;
				answer++;
			}
		}
	}
	return answer;
}

int main(void){
	char * s1 = "abcabc";
	char * s2 = "ab";
	printf("%d", naive_string_search(s1, s2));
	return 0;
}
