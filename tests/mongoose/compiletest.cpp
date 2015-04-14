#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mongoose.h"

//static const char *s_no_cache_header =  "Cache-Control: max-age=0, post-check=0, pre-check=0, no-store, no-cache, must-revalidate\r\n";

static void handle_restful_call(struct mg_connection *conn) {
  mg_printf_data(conn, "{ \"msg\": \"Hello world\" }");
}

static int ev_handler(struct mg_connection *conn, enum mg_event ev) {
  switch (ev) {
    case MG_AUTH: return MG_TRUE;
    case MG_REQUEST:
      if (!strcmp(conn->uri, "/hello")) {
        handle_restful_call(conn);
        return MG_TRUE;
      }
      return MG_FALSE;
    default: return MG_FALSE;
  }
}

int main(void) {
  struct mg_server *server;

  // Create and configure the server
  server = mg_create_server(NULL, ev_handler);
  mg_set_option(server, "listening_port", "8080");

  // Serve request. Hit Ctrl-C to terminate the program
  printf("Starting on port %s\n", mg_get_option(server, "listening_port"));
  for (;;) {
    mg_poll_server(server, 1000);
  }

  // Cleanup, and free server instance
  mg_destroy_server(&server);

  return 0;
}
