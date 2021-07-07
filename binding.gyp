{
  "targets": [
    {
      "target_name": "lgpio",
      "cflags": [ '-fexceptions' ],
      "cflags_cc": [ '-fexceptions' ],
      "sources": [
        "./src/binding/helpers.cpp",
        "./src/binding/chip.cpp",
        "./src/binding/gpio.cpp",
        "./src/binding/tx.cpp",
        "./src/binding/alerts.cpp",
        "./src/binding/utils.cpp",
        "./src/binding/index.cpp"
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      "libraries": [
        "-llgpio"
      ],
      "defines": [
        "NAPI_CPP_EXCEPTIONS"
      ]
    }
  ]
}
