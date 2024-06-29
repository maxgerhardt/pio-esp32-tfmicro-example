set(srcs
  "main.cpp"
  "esp-nn-test-funcs/basic_math_test.c"
  "esp-nn-test-funcs/convolution_test.c"
  "esp-nn-test-funcs/fully_connected_test.c"
  "esp-nn-test-funcs/pooling_test.c"
  "esp-nn-test-funcs/relu_test.c"
  "esp-nn-test-funcs/softmax_test.c")
idf_component_register(
    SRCS ${srcs}
    REQUIRES esp_timer esp-nn)