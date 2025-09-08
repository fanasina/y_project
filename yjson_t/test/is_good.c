#include "ftest/ftest.h"
#include "fmock/fmock.h"


#include "json_t/json_t.h"

TEST(string_val){
  
  char *val = "\"Hello! it's a string\"";

  struct js_value *js = create_js_value_string(val, NULL);
  
  LOG("js type = %d\n",js->code_type);
  LOG("js len = %ld\n",js->length);
  LOG(" js val = %s\n", js->type.string);

  free_js_value(js);
}
TEST(number){
  
  char *val = "3.14";

  struct js_value *js = create_js_value_number(val, NULL);
  
  LOG("js type = %d\n",js->code_type);
  LOG("js len = %ld\n",js->length);
  LOG(" js val = %Lf\n", js->type.number);

  free_js_value(js);
}
TEST(object_val){
  
  char *val = "{ \"message\" : \"Hello! it's a string\"  , \"age\" : 48 , \"speaker\" : \" the president \" }";
  struct js_value *js = create_js_value_object(val, NULL);

  LOG("key : %s\n lenKey: %ld \n",js->type.object.key, js->type.object.key_length);

/*
  LOG("value : %s\n",js->type.object.value->type.string);
  LOG("value : %Lf\n",js->type.object.next_object->type.object.value->type.number);
  LOG("value : %s\n",js->type.object.next_object->type.object.next_object->type.object.value->type.string);
*/

  print_js_value(js);

  char *rrjson = original_string_js_value(js);
  printf("original :%s\n",rrjson);
  char *rrjson1 = original_string_js_value(js->type.object.next_object);
  printf("original 1 :%s\n",rrjson1);

  free_js_value(js);
 
 free(rrjson);
 free(rrjson1);

  LOG("line %d\n",__LINE__);
}
TEST(array_val){
  
  char *val = "[ \"message\" , \"Hello! it's a string\"  , { \"age\" : 48  , \"speaker\" : \" the president \" }, 45 , true ]";
  //char *val = "[ \"message\" , \"Hello! it's a string\"  , { \"age\" : 48 } , {\"speaker\" : \" the president \" } , 25, \"tttt\"  ]";
  struct js_value *js = create_js_value_array(val, NULL);

//  LOG("key : %s\n lenKey: %ld \n",js->type.object.key, js->type.object.key_length);

/*
  LOG("value : %s\n",js->type.object.value->type.string);
  LOG("value : %Lf\n",js->type.object.next_object->type.object.value->type.number);
  LOG("value : %s\n",js->type.object.next_object->type.object.next_object->type.object.value->type.string);
*/

  print_js_value(js);

/*
  char *rrjson = original_string_js_value(js);
  printf("original :%s\n",rrjson);
  char *rrjson1 = original_string_js_value(js->type.array.next_element);
  printf("original 1 :%s\n",rrjson1);
*/
  free_js_value(js);
 
// free(rrjson);
// free(rrjson1);
  //LOG("%s\n",__LINE__);
  LOG("line %d\n",__LINE__);

}
TEST(general_val){
  
  char *val = "{ \"array\" : [ \"message\" , \"Hello! it's a string\"  , { \"age\" : 48  , \"speaker\" : \" the president \" }, 45 , true ] }";
  //char *val = "[ \"message\" , \"Hello! it's a string\"  , { \"age\" : 48 } , {\"speaker\" : \" the president \" } , 25, \"tttt\"  ]";
  struct js_value *js = create_js_value(val, NULL);

//  LOG("key : %s\n lenKey: %ld \n",js->type.object.key, js->type.object.key_length);

/*
  LOG("value : %s\n",js->type.object.value->type.string);
  LOG("value : %Lf\n",js->type.object.next_object->type.object.value->type.number);
  LOG("value : %s\n",js->type.object.next_object->type.object.next_object->type.object.value->type.string);
*/

  print_js_value(js);

/*
  char *rrjson = original_string_js_value(js);
  printf("original :%s\n",rrjson);
  char *rrjson1 = original_string_js_value(js->type.array.next_element);
  printf("original 1 :%s\n",rrjson1);
*/
  free_js_value(js);
 
// free(rrjson);
// free(rrjson1);
  LOG("line %d\n",__LINE__);

}

TEST(general_val2){
  
  char *val = "{ \"array\" : [ \"message\" , \"Hello! it's a string\" ,  [{},{},[ [ ] ] ] , { \"age\" : 48  , \"speaker\" : \" the president \" } , 45 , true ] , \"second\" : 324.1 , \"person\" : { \"name\" : \"Fana\" , \"age\" : 37 , \"genre\" : \"male\" , \"married\" : false , \"note\" : [2.1,4.45,4,10, { \"math\" : 17.1, \"malagasy\" : 12, \"eps\" : [ 5, 6 , 4 ] }] } , \"nul\" : { } }";
  //char *val = "{ \"array\" : [ \"message\", \"Hello! it's a string\", { \"age\" : 48, \"speaker\" : \" the president \" }, 45, true ], \"second\" : [ 324.1, 1 , { \"math\" : 17.1 } ]  }";
  //char *val = "[ \"message\" , \"Hello! it's a string\"  , { \"age\" : 48 } , {\"speaker\" : \" the president \" } , 25, \"tttt\"  ]";
  struct js_value *js = create_js_value(val, NULL);

//  LOG("key : %s\n lenKey: %ld \n",js->type.object.key, js->type.object.key_length);

/*
  LOG("value : %s\n",js->type.object.value->type.string);
  LOG("value : %Lf\n",js->type.object.next_object->type.object.value->type.number);
  LOG("value : %s\n",js->type.object.next_object->type.object.next_object->type.object.value->type.string);
*/

  print_js_value(js);

/*
  char *rrjson = original_string_js_value(js);
  printf("original :%s\n",rrjson);
  char *rrjson1 = original_string_js_value(js->type.array.next_element);
  printf("original 1 :%s\n",rrjson1);
*/
  free_js_value(js);
  LOG("line %d\n",__LINE__);
 
// free(rrjson);
// free(rrjson1);

}


TEST(add_val){
  
  char *val = "{ \"array\" : [ \"message\" , \"Hello! it's a string\" ,  [{},{},[ [ ] ] ] , { \"age\" : 48  , \"speaker\" : \" the president \" } , 45 , true ] , \"second\" : 324.1 , \"person\" : { \"name\" : \"Fana\" , \"age\" : 37 , \"genre\" : \"male\" , \"married\" : false , \"note\" : [2.1,4.45,4,10, { \"math\" : 17.1, \"malagasy\" : 12, \"eps\" : [ 5, 6 , 4 ] }] } , \"nul\" : { } }";
  //char *val = "{ \"array\" : [ \"message\", \"Hello! it's a string\", { \"age\" : 48, \"speaker\" : \" the president \" }, 45, true ], \"second\" : [ 324.1, 1 , { \"math\" : 17.1 } ]  }";
  //char *val = "[ \"message\" , \"Hello! it's a string\"  , { \"age\" : 48 } , {\"speaker\" : \" the president \" } , 25, \"tttt\"  ]";

  struct js_value *js = create_js_value(val, NULL);

  char *add ="{ \"add0\" : 0.0 , \"addname\" : \"Fanasina\"  }";
  
  struct js_value *js_add = create_js_value(add, NULL);

  
  print_js_value(js);
  add_js_value_index(10, js_add, &js);
  print_js_value(js);
  free_js_value(js);
  LOG("line %d\n",__LINE__);
 
// free(rrjson);
// free(rrjson1);

}
TEST(append_val){

  char *val = "{ \"array\" : [ \"message\" , \"Hello! it's a string\" ,  [{},{},[ [ ] ] ] , { \"age\" : 48  , \"speaker\" : \" the president \" } , 45 , true ] , \"second\" : 324.1 , \"person\" : { \"name\" : \"Fana\" , \"age\" : 37 , \"genre\" : \"male\" , \"married\" : false , \"note\" : [2.1,4.45,4,10, { \"math\" : 17.1, \"malagasy\" : 12, \"eps\" : [ 5, 6 , 4 ] }] } , \"nul\" : { } }";
  //char *val = "{ \"array\" : [ \"message\", \"Hello! it's a string\", { \"age\" : 48, \"speaker\" : \" the president \" }, 45, true ], \"second\" : [ 324.1, 1 , { \"math\" : 17.1 } ]  }";
  //char *val = "[ \"message\" , \"Hello! it's a string\"  , { \"age\" : 48 } , {\"speaker\" : \" the president \" } , 25, \"tttt\"  ]";

  struct js_value *js = create_js_value(val, NULL);

  //char *add ="{ \"add0\" : 0.0  }";
  char *add ="{ \"add0\" : 0.0  }";

//  struct js_value *js_add = create_js_value(add, NULL);


  print_js_value(js);
//  add_js_value_index(10, js_add, &js);
  append_js_value(js,add);
  print_js_value(js);

  char *add_arr ="{ \"array\" : [ 0.0 ]  }";
  append_js_value(js,add_arr);
  print_js_value(js);
  

  free_js_value(js);
  LOG("\nline %d\n",__LINE__);


}
TEST(delete_index){

  //char *val = "{ \"array\" : [ \"message\" , \"Hello! it's a string\" ,  [{},{},[ [ ] ] ] , { \"age\" : 48  , \"speaker\" : \" the president \" } , 45 , true ] , \"second\" : 324.1 , \"person\" : { \"name\" : \"Fana\" , \"age\" : 37 , \"genre\" : \"male\" , \"married\" : false , \"note\" : [2.1,4.45,4,10, { \"math\" : 17.1, \"malagasy\" : 12, \"eps\" : [ 5, 6 , 4 ] }] } , \"nul\" : { } }";
  char *val = "{ \"array\" : [ \"message\" , \"Hello! it's a string\" ,  [{},{},[ [ ] ] ] , { \"age\" : 48  , \"speaker\" : \" the president \" } , 45 , true ] , \"second\" : 324.1 , \"person\" : { \"name\" : \"Fana\" , \"age\" : 37 , \"genre\" : \"male\" , \"married\" : false  } , \"nul\" : { } }";

  struct js_value *js = create_js_value(val, NULL);

  print_js_value(js);
  delete_index_js_value(2, &js);

  print_js_value(js);
  

  free_js_value(js);
  LOG("line %d\n",__LINE__);


}

TEST(delete_key){

  char *val = "{ \"array\" : [ \"message\" , \"Hello! it's a string\" ,  [{},{},[ [ ] ] ] , { \"age\" : 48  , \"speaker\" : \" the president \" } , 45 , true ] , \"second\" : 324.1 , \"person\" : { \"name\" : \"Fana\" , \"age\" : 37 , \"genre\" : \"male\" , \"married\" : false , \"note\" : [2.1,4.45,4,10, { \"math\" : 17.1, \"malagasy\" : 12, \"eps\" : [ 5, 6 , 4 ] }] } , \"nul\" : { } }";

  struct js_value *js = create_js_value(val, NULL);

  print_js_value(js);
  delete_key_js_value("second", &js);

  print_js_value(js);

  

  free_js_value(js);
  LOG("line %d\n",__LINE__);


}
TEST(delete_key_format_in){

  char *val = 
" { "
" \"array\" : "
"    [ "
"     \"message\", "
"     \"Hello! it's a string\", "
"        [ "
"            { "
"            \"\" : null"
"            } , "
"            { "
"            \"\" : null"
"            } , "
"            [ "
"                [ "
"                 null"
"                ] "
"            ] "
"        ] , "
"        { "
"        \"age\" : 48.000000, "
"        \"speaker\" : \" the president \""
"        } , "
"     45.000000, "
"     true"
"    ] , "
" \"person\" : "
"    { "
"    \"name\" : \"Fana\", "
"    \"age\" : 37.000000, "
"    \"genre\" : \"male\", "
"    \"married\" : false, "
"    \"note\" : "
"        [ "
"         2.100000, "
"         4.450000, "
"         4.000000, "
"         10.000000, "
"            { "
"            \"math\" : 17.100000, "
"            \"malagasy\" : 12.000000, "
"            \"eps\" : "
"                [ "
"                 5.000000, "
"                 6.000000, "
"                 4.000000"
"                ] "
"            } "
"        ] "
"    } , "
" \"nul\" : "
"    { "
"    \"\" : null"
"    } "
" }";

//  "{ \"array\" : [ \"message\" , \"Hello! it's a string\" ,  [{},{},[ [ ] ] ] , { \"age\" : 48  , \"speaker\" : \" the president \" } , 45 , true ] , \"second\" : 324.1 , \"person\" : { \"name\" : \"Fana\" , \"age\" : 37 , \"genre\" : \"male\" , \"married\" : false , \"note\" : [2.1,4.45,4,10, { \"math\" : 17.1, \"malagasy\" : 12, \"eps\" : [ 5, 6 , 4 ] }] } , \"nul\" : { } }";

  struct js_value *js = create_js_value(val, NULL);

  print_js_value(js);
  delete_key_js_value("person", &js);
  //delete_key_js_value("nul", &js);

  print_js_value(js);

  

  free_js_value(js);
  LOG("line %d\n",__LINE__);


}
TEST(delete_key_format_in2){
  char *val= " { \"person\": \"Hee\" , \"second\" : 3.22 } ";
#if 0
" {"
" \"array\" :"
"    ["
"     \"message\","
"     \"Hello! it's a string\","
"        ["
"            {"
"            \"\" : null"
"            } ,"
"            {"
"            \"\" : null"
"            } ,"
"            ["
"                ["
"                 null"
"                ]"
"            ]"
"        ] ,"
"        {"
"        \"age\" : 48.000000,"
"        \"speaker\" : \" the president \""
"        } ,"
"     45.000000,"
"     true"
"    ] ,"
" \"second\" : 324.100000,"
" \"person\" :"
"    {"
"    \"name\" : \"Fana\","
"    \"age\" : 37.000000,"
"    \"genre\" : \"male\","
"    \"married\" : false,"
"    \"note\" :"
"        ["
"         2.100000,"
"         4.450000,"
"         4.000000,"
"         10.000000,"
"            {"
"            \"math\" : 17.100000,"
"            \"malagasy\" : 12.000000,"
"            \"eps\" :"
"                ["
"                 5.000000,"
"                 6.000000,"
"                 4.000000"
"                ]"
"            }"
"        ]"
"    } ,"
" \"nul\" :"
"    {"
"    \"\" : null"
"    }"
" } ";
#endif 

#if 0
  "{ \"array\" : [ \"message\" , \"Hello! it's a string\" ,  [{},{},[ [ ] ] ] , { \"age\" : 48  , \"speaker\" : \" the president \" } , 45 , true ] , \"second\" : 324.1 , \"person\" : { \"name\" : \"Fana\" , \"age\" : 37 , \"genre\" : \"male\" , \"married\" : false , \"note\" : [2.1,4.45,4,10, { \"math\" : 17.1, \"malagasy\" : 12, \"eps\" : [ 5, 6 , 4 ] }] } , \"nul\" : { } }";
#endif

#if 0
char *val =" { "
" \"person\" : "
"    { "
"    \"name\" : \"Fana\", "
"    \"age\" : 37.000000, "
"    \"genre\" : \"male\", "
"    \"married\" : false, "
"    \"note\" : "
"        [ "
"         2.100000, "
"         4.450000, "
"         4.000000, "
"         10.000000, "
"            { "
"            \"math\" : 17.100000, "
"            \"malagasy\" : 12.000000, "
"            \"eps\" : "
"                [ "
"                 5.000000, "
"                 6.000000, "
"                 4.000000"
"                ] "
"            } "
"        ] "
"    } , "
" \"nul\" : "
"    { "
"    \"\" : null"
"    } "
" }";
#endif

//  "{ \"array\" : [ \"message\" , \"Hello! it's a string\" ,  [{},{},[ [ ] ] ] , { \"age\" : 48  , \"speaker\" : \" the president \" } , 45 , true ] , \"second\" : 324.1 , \"person\" : { \"name\" : \"Fana\" , \"age\" : 37 , \"genre\" : \"male\" , \"married\" : false , \"note\" : [2.1,4.45,4,10, { \"math\" : 17.1, \"malagasy\" : 12, \"eps\" : [ 5, 6 , 4 ] }] } , \"nul\" : { } }";

  struct js_value *tmp, *js = create_js_value(val, NULL);

  print_js_value(js);
  tmp = js;
  delete_key_js_value("person", &js);
  
  EXPECT_EQ(0, (js == tmp));

  print_js_value(js);

  

  free_js_value(js);
  LOG("line %d\n",__LINE__);


}
TEST(general_val_with_extra_value){

  char *val = "{ \"header\" : [ \"message\" , \"Hello! it's a string\" ,  [{},{},[ [ ] ] ] , { \"age\" : 48  , \"speaker\" : \" the president \" } , 45 , true ] , \"second\" : 324.1 , \"person\" : { \"name\" : \"Fana\" , \"age\" : 37 , \"genre\" : \"male\" , \"married\" : false , \"note\" : [2.1,4.45,4,10, { \"math\" : 17.1, \"malagasy\" : 12, \"eps\" : [ 5, 6 , 4 ] }] } , \"nul\" : { } } here extra string";
 struct js_value *js = create_js_value(val, NULL);


  print_js_value(js);
  LOG("\ndebug: strlen(val)=%ld\n",strlen(val));
  LOG("debug: js->length=%ld\n",js->length);

  LOG("extra value : %s\n",val+js_org_str_length(js));

 free_js_value(js);
  LOG("line %d\n",__LINE__);

}
TEST(string_general_val_with_extra_value){

  char *val = " \"header\" : [ \"message\" , \"Hello! it's a string\" ,  [{},{},[ [ ] ] ] , { \"age\" : 48  , \"speaker\" : \" the president \" } , 45 , true ] , \"second\" : 324.1 , \"person\" : { \"name\" : \"Fana\" , \"age\" : 37 , \"genre\" : \"male\" , \"married\" : false , \"note\" : [2.1,4.45,4,10, { \"math\" : 17.1, \"malagasy\" : 12, \"eps\" : [ 5, 6 , 4 ] }] } , \"nul\" : { }  here extra string";
 struct js_value *js = create_js_value(val, NULL);


  print_js_value(js);
  LOG("\ndebug: strlen(val)=%ld\n",strlen(val));
  LOG("debug: js->=str_value(%s)\n",js->str_value);
  LOG("debug: js->length=%ld\n",js->length);
  LOG("debug: js->code_type=%d\n",js->code_type);

  LOG("extra value : (%s)\n",val+js_org_str_length(js)); // if string add 1

 free_js_value(js);
  LOG("line %d\n",__LINE__);

}
TEST(general_val_string_with_extra_value){

  char *val = "-1 header : [ \"message\" , \"Hello! it's a string\" ,  [{},{},[ [ ] ] ] , { \"age\" : 48  , \"speaker\" : \" the president \" } , 45 , true ] , \"second\" : 324.1 , \"person\" : { \"name\" : \"Fana\" , \"age\" : 37 , \"genre\" : \"male\" , \"married\" : false , \"note\" : [2.1,4.45,4,10, { \"math\" : 17.1, \"malagasy\" : 12, \"eps\" : [ 5, 6 , 4 ] }] } , \"nul\" : { }  here extra string";
 struct js_value *js = create_js_value(val, NULL);


  print_js_value(js);
  LOG("\ndebug: strlen(val)=%ld\n",strlen(val));
  LOG("debug: js->=str_value(%s)\n",js->str_value);
  LOG("debug: js->length=%ld\n",js->length);
  LOG("debug: js->code_type=%d\n",js->code_type);

  LOG("extra value : (%s)\n",val+js_org_str_length(js)); // if string add 1

 free_js_value(js);
  LOG("line %d\n",__LINE__);

}




int main(int argc, char **argv){
  

  run_all_tests_args(argc, argv);

  return 0;
}
