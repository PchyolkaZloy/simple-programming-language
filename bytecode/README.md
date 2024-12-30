### Подключение в вашем модуле

```cmake
# Подключаем парсер
add_library(Parser STATIC IMPORTED)
set_target_properties(Parser PROPERTIES
    IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../parser/build/libParser.a
)

# Указываем, где искать заголовочные файлы
include_directories(${CMAKE_SOURCE_DIR}/../parser/include)

target_link_libraries(YourProject Parser)
```