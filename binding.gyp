{
  "targets": [
    {
      "target_name": "lgpio",
      "cflags": [ '-fexceptions' ],
      "cflags_cc": [ '-fexceptions' ],
      "sources": [
        "./src/binding/helpers.cpp",
        "./src/binding/alerts.cpp",
        "./src/binding/chip.cpp",
        "./src/binding/gpio.cpp",
        "./src/binding/i2c.cpp",
        "./src/binding/serial.cpp",
        "./src/binding/spi.cpp",
        "./src/binding/tx.cpp",
        "./src/binding/utils.cpp",
        "./src/binding/index.cpp"
      ],
      "dependencies": [
        "<!(node -p \"require('node-addon-api').gyp\")"
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
