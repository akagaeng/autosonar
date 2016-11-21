/*
코드 작성 순서
1. sonar-project.properties 파일을 만든다.
2. sonar-project.properties 파일의 내용을 작성한다.
3. sonar-runner를 실행한다.
4. (코드랑 상관없음) sonarqube dashboard에서 분석된 내용을 확인한다.
<sonar-project.properties>
# Required metadata
sonar.projectKey = org.sonarqube:java - simple - sq - scanner
sonar.projectName = Java::Simple Project Not Compiled::SonarQube Scanner
sonar.projectVersion = 1.0

# Comma - separated paths to directories with sources(required)
sonar.sources = src

# Language
sonar.language = java

# Encoding of the source files
sonar.sourceEncoding = UTF - 8
*/

#include <stdio.h>
#include <string.h>

int main(){
	FILE *fp;
	char projectKey[30] = { 0, };
	char projectName[30] = { 0, };
	char projectVersion[30] = { 0, };
	char sourcePath[30] = { 0, };
	char langChoice[3][30] = { "java", "c", "web" };
	char language[30] = { 0, };
	char textBuffer[65535] = { 0, };

	int langch = 0;
	int cnt = 0;
	int i = 0;

	for (cnt = 1; cnt <= 5;cnt++){
		system("cls");
		printf("\n==========SonarQube Automated Runner Program==========\n\n");
		printf(" projectKey: %s\n", projectKey);
		printf(" projectName: %s\n", projectName);
		printf(" projectVersion: %s\n", projectVersion);
		printf(" sourcePath: %s\n", sourcePath);
		printf(" language: %s\n", language);
		printf("\n======================================================\n\n");

		switch (cnt){
			case 1:
				printf("Make <sonar-project.properties> file (1/5)\n");
				printf("input Project Key: ");
				scanf("%s", projectKey);
				break;
			case 2:
				printf("Make <sonar-project.properties> file (2/5)\n");
				printf("input Project Key: ");
				scanf("%s", projectName);
				break;
			case 3:
				printf("Make <sonar-project.properties> file (3/5)\n");
				printf("input Project Key: ");
				scanf("%s", projectVersion);
				break;
			case 4:
				system("dir");
				printf("\n======================================================\n\n");
				printf("Make <sonar-project.properties> file (4/5)\n");
				printf("input sourcePath: ");
				scanf("%s", sourcePath);
				break;
			case 5:
				printf("Make <sonar-project.properties> file (5/5)\n");
				printf("1: java\n2: c/c++\n3: web(html, jsp)\n");
				printf("input language number: ");
				scanf("%d", &langch);
				sprintf(language, "%s", langChoice[langch-1]);
				break;

			default: break;

			}//end switch
	}//end for
	
		sprintf(textBuffer, "# Required metadata\nsonar.projectKey=%s\nsonar.projectName=%s\nsonar.projectVersion=%s\n\n# Comma - separated paths to directories with sources(required)\nsonar.sources=%s\n\n# Language\nsonar.language=%s\n\n# Encoding of the source files\nsonar.sourceEncoding=UTF-8", projectKey, projectName, projectVersion, sourcePath, language);

		//printf("%s\n", textBuffer);

		fp = fopen("sonar-project.properties", "w");

		for (i = 0; i < strlen(textBuffer); i++){
			fprintf(fp, "%c", textBuffer[i]);
		}
		fclose(fp);

		system("cls");
		printf("sonar-project.properties 파일을 성공적으로 생성하였습니다.\n");
		printf("sonar-runner를 실행합니다.\n\n");
		system("sonar-runner.bat");

	return 0;
}