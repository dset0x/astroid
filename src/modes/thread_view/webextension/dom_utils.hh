# pragma once

# include <string>
# include <vector>
# include <gio/gio.h>

#ifdef ASTROID_WEBEXTENSION
# include <webkit2/webkit-web-extension.h>
# else
# include <webkit2/webkit2.h>
# endif

# include "proto.hh"

using std::vector;

namespace Astroid {
  class DomUtils {
    public:
      static std::string assemble_data_uri (const char *, const gchar *, gsize);
      static std::string assemble_data_uri (const std::string mime_type, const std::string data);

#ifdef ASTROID_WEBEXTENSION

      static WebKitDOMHTMLElement * make_message_div (WebKitDOMDocument *);

      /* webkit dom utils */
      static WebKitDOMHTMLElement * clone_get_by_id (
          WebKitDOMDocument * node,
          ustring         id,
          bool            deep = true);

      static WebKitDOMHTMLElement * clone_node (
          WebKitDOMNode * node,
          bool            deep = true);

      static WebKitDOMHTMLElement * clone_select (
          WebKitDOMNode * node,
          ustring         selector,
          bool            deep = true);

      static WebKitDOMHTMLElement * select (
          WebKitDOMNode * node,
          ustring         selector);

      static WebKitDOMElement * get_by_id (
          WebKitDOMDocument * n, ustring id);

      static bool switch_class (WebKitDOMDOMTokenList *, ustring, bool);

      static bool in_view (WebKitWebPage * page, ustring eid);
# endif
  };
}

