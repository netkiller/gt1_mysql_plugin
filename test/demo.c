#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../curl.h"
#include "../protocol.h"


void test(char *result) {
	xmlDocPtr doc = xmlParseDoc(result);
	if (doc == NULL ) {
		fprintf(stderr,"Document not parsed successfully. \n");
		return;
	}
	xmlNodePtr cur = xmlDocGetRootElement(doc);
	
	if (cur == NULL) {
		fprintf(stderr,"empty document\n");
		xmlFreeDoc(doc);
		return;
	}
	
	if (xmlStrcmp(cur->name, (const xmlChar *) "Result")) {
		fprintf(stderr,"document of the wrong type, root node != story");
		xmlFreeDoc(doc);
		return;
	}

	xmlChar *uri;
	//cur = cur->xmlChildrenNode;
	//while (cur != NULL) {
	if ((!xmlStrcmp(cur->name, (const xmlChar *)"Result"))) {
		    uri = xmlGetProp(cur, "Code");
		    printf("uri: %s\n", uri);
		    xmlFree(uri);
	    //}
	    //cur = cur->next;
		printf("uri: %s\n", xmlGetProp(cur, "Login"));
		printf("uri: %s\n", xmlGetProp(cur, "Pwd"));
	}
	
	
	xmlFreeDoc(doc);
	return;
}

int main(int argc, char **argv)
{
	char *xmlpro;
	char *html;
	xmlpro = protocol_demo("test");
	//printf("xml: %s\n\n", xmlpro);	
	
	html = conn("http://59.152.226.199:3355/add_demo_member.ucs", xmlpro);
	
	
	printf("html: %s \n", html);	
	test(html);
}
