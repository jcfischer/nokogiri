#include <xml_element_decl.h>

/*
 * call-seq:
 *  element_type
 *
 * The element_type
 */
static VALUE element_type(VALUE self)
{
  xmlElementPtr node;
  Data_Get_Struct(self, xmlElement, node);
  return INT2NUM((int)node->etype);
}

VALUE cNokogiriXmlElementDecl;

void init_xml_element_decl()
{
  VALUE nokogiri = rb_define_module("Nokogiri");
  VALUE xml = rb_define_module_under(nokogiri, "XML");
  VALUE node = rb_define_class_under(xml, "Node", rb_cObject);
  VALUE klass = rb_define_class_under(xml, "ElementDecl", node);

  cNokogiriXmlElementDecl = klass;

  rb_define_method(klass, "element_type", element_type, 0);
}
