#include <stdio.h>
#include <math.h>

#include <libxml/HTMLtree.h>

#if defined(LIBXML_TREE_ENABLED) && defined(LIBXML_OUTPUT_ENABLED)

int main(int argc, char **argv)
{
	xmlDocPtr doc = NULL;       	/* document pointer */
	xmlNodePtr root_node = NULL;	/* node pointer */

	LIBXML_TEST_VERSION;

	/*
	 * Creates a new document, a node and set it as a root node
	 */
	doc = htmlNewDocNoDtD(NULL, NULL);
	root_node = xmlNewNode(NULL, BAD_CAST "html");
	xmlNewProp(root_node, BAD_CAST "lang", BAD_CAST "en");
	xmlDocSetRootElement(doc, root_node);

	/*
	 * Creates a Document Type Definition (DTD) declaration. Isn't mandatory.
	 */
	xmlCreateIntSubset(doc, BAD_CAST "html", NULL, NULL);

	/*
	 * xmlNewChild() creates a new node, which is "attached" as child node
	 * of root_node node.
	 */
	xmlNodePtr head = xmlNewChild(root_node, NULL, BAD_CAST "head", NULL);
	xmlNodePtr body = xmlNewChild(root_node, NULL, BAD_CAST "body", NULL);
    xmlNodePtr title = xmlNewChild(head, NULL, BAD_CAST "title", BAD_CAST "Assignment 1");




	//  	My code starts here | | | |
	//							v v v v

	xmlNodePtr table = xmlNewChild(body, NULL, BAD_CAST "table", NULL);
	xmlNewProp(table, BAD_CAST "align", BAD_CAST "left");
	xmlNewProp(table, BAD_CAST "border", BAD_CAST "1");
	xmlNewProp(table, BAD_CAST "cellspacing", BAD_CAST "0");
	xmlNewProp(table, BAD_CAST "cellpadding", BAD_CAST "0");
	xmlNewProp(table, BAD_CAST "width", BAD_CAST "100%");
	xmlNodePtr caption = xmlNewChild(table, NULL, BAD_CAST "caption", NULL);
	xmlNodePtr strong = xmlNewChild(caption, NULL, BAD_CAST "strong", BAD_CAST "Temperature and Dew Point for SAN DIEGO INTERNATIONAL AIRPORT, CA US");


	xmlNodePtr thead = xmlNewChild(table, NULL, BAD_CAST "thead", NULL);
	xmlNodePtr tr1 = xmlNewChild(thead, NULL, BAD_CAST "tr", NULL);
	xmlNodePtr th1 = xmlNewChild(tr1, NULL, BAD_CAST "th", NULL);
	xmlNewProp(th1, BAD_CAST "rowspan", BAD_CAST "2");
	xmlNodePtr img = xmlNewChild(th1, NULL, BAD_CAST "img", NULL);
	xmlNewProp(img, BAD_CAST "src", BAD_CAST "noaa.png");
	xmlNewProp(img, BAD_CAST "alt", BAD_CAST "NOAA Logo");
	xmlNewProp(img, BAD_CAST "border", BAD_CAST "0");
	xmlNewProp(img, BAD_CAST "align", BAD_CAST "left");
	xmlNewProp(img, BAD_CAST "width", BAD_CAST "100");
	//xmlNewProp(img, BAD_CAST "height", BAD_CAST "");
	xmlNodePtr th2 = xmlNewChild(tr1, NULL, BAD_CAST "th", NULL);
	xmlNodePtr strong2 = xmlNewChild(th2, NULL, BAD_CAST "strong", BAD_CAST "LATITUDE");
	xmlNodePtr th3 = xmlNewChild(tr1, NULL, BAD_CAST "th", NULL);
	xmlNodePtr strong3 = xmlNewChild(th3, NULL, BAD_CAST "strong", BAD_CAST "LONGITUDE");


	xmlNodePtr tr2 = xmlNewChild(thead, NULL, BAD_CAST "tr", NULL);

	xmlNodePtr th4 = xmlNewChild(tr2, NULL, BAD_CAST "th", NULL);
	xmlNodePtr th5 = xmlNewChild(tr2, NULL, BAD_CAST "th", NULL);


	xmlNodePtr tbody = xmlNewChild(table, NULL, BAD_CAST "tbody", NULL);
	xmlNodePtr tr3 = xmlNewChild(tbody, NULL, BAD_CAST "tr", NULL);
	xmlNodePtr td1 = xmlNewChild(tr3, NULL, BAD_CAST "td", NULL);
	xmlNodePtr strong6 = xmlNewChild(td1, NULL, BAD_CAST "strong", BAD_CAST "DATE");
	xmlNodePtr td2 = xmlNewChild(tr3, NULL, BAD_CAST "td", NULL);
	xmlNodePtr td3 = xmlNewChild(tr3, NULL, BAD_CAST "td", NULL);


	// Setting aside stack memory for xmlNodePtr Row, data and table elements
	xmlNodePtr node_pointer_array_row [40];
	xmlNodePtr node_pointer_array_data_date [40];
	xmlNodePtr node_pointer_array_data_dewp [40];
	xmlNodePtr node_pointer_array_data_temp [40];
	// Setting aside stack memory for xmlNodePtr Row, data and table elements


	// This code reads from file input

	FILE *the_file = fopen("data.csv", "r");
	if (the_file == NULL)
	{
		perror("Unable to open the file.");
		exit(1);
	}

	int loop_counter = 1;
	int token_counter = 1;
	char line[1024];
	while(fgets(line, sizeof(line), the_file))
	{
		char * token;
		token = strtok(line, ",");

		while(token != NULL)
		{
			// Fill in table and row data accordingly  		| | | |
			// 												v v v v

			// This fills in the appropriate coordinates 32.7336 in the thead brackets 
			if(loop_counter == 2 && token_counter == 3) { xmlNodePtr strong4 = xmlNewChild(th4, NULL, BAD_CAST "strong", BAD_CAST token); }
			// This fills in the appropriate coordinates -117.1831 in the thead brackets
			else if(loop_counter == 2 && token_counter == 4) { xmlNodePtr strong5 = xmlNewChild(th5, NULL, BAD_CAST "strong", BAD_CAST token); }
			//  This fills in the appropriate title (HLY-DEWP-NORMAL in tbody tags
			else if(loop_counter == 1 && token_counter == 15)	{ xmlNodePtr strong7 = xmlNewChild(td2, NULL, BAD_CAST "strong", BAD_CAST token); }
			// This fills in the appropriate title (HLY-TEMP-NORMAL) in tbody tags
			else if(loop_counter == 1 && token_counter == 23)	{ xmlNodePtr strong8 = xmlNewChild(td3, NULL, BAD_CAST "strong", BAD_CAST token); }
			// This fills in the first colummn with the "Date" table data using the right tokens
			else if(loop_counter > 1 && (token_counter == 6))
			{
				node_pointer_array_row[loop_counter - 1] = xmlNewChild(tbody, NULL, BAD_CAST "tr", NULL);
				node_pointer_array_data_date[loop_counter - 1] = xmlNewChild(node_pointer_array_row[loop_counter - 1], NULL, BAD_CAST "td", token);
			}
			// This fills in the first colummn with the "HLY-DEWP-NORMAL" table data using the right tokens
			else if(loop_counter > 1 && (token_counter == 15))
			{
				node_pointer_array_data_date[loop_counter - 1] = xmlNewChild(node_pointer_array_row[loop_counter - 1], NULL, BAD_CAST "td", token);
			}
			// This fills in the first colummn with the "HLY-TEMP-NORMAL" date table data using the right tokens
			else if(loop_counter > 1 && (token_counter == 23))
			{
				node_pointer_array_data_date[loop_counter - 1] = xmlNewChild(node_pointer_array_row[loop_counter - 1], NULL, BAD_CAST "td", token);
			}

			// Fill in table and row data accordingly  		^ ^ ^ ^
			//							   			   		| | | |

			if(token_counter == 1 && loop_counter > 1)
			{
				token = strtok(NULL, "\"");
			}
			else token = strtok(NULL, ",");
			token_counter++;
		}
		token_counter = 1;
		loop_counter++;
	}
	//		My code ends here  ^ ^ ^ ^
	//						   | | | |


	htmlSaveFileFormat(argc > 1 ? argv[1] : "-", doc, "UTF-8", 1);

	/*free the document */
	xmlFreeDoc(doc);

	/*
	 *Free the global variables that may
	 *have been allocated by the parser.
	 */
	xmlCleanupParser();

	/*
	 * this is to debug memory for regression tests
	 */
	xmlMemoryDump();

	return(0);
}
#else
int main(void) {
	fprintf(stderr, "tree support not compiled in\n");
	exit(1);
}
#endif
