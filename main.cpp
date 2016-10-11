#include <cstdio>
#include <system_error>
#include <string>

int main()
{
    for (int i = 0; i < 10; ++i) {
        auto ecode_sys = std::error_code(i, std::system_category());
        auto ecode_gen = std::error_code(i, std::generic_category());
        auto econd_sys = std::error_condition(i, std::system_category());
        auto econd_gen = std::error_condition(i, std::generic_category());
        auto ecodecond_sys = ecode_sys.default_error_condition();
        auto ecodecond_gen = ecode_gen.default_error_condition();

        printf("**** code: %d ****\n", i);
        printf("error_code/sys: %s\n", ecode_sys.message().c_str());
        printf("error_code/gen: %s\n", ecode_gen.message().c_str());
        printf("error_condition/sys: %s\n", econd_sys.message().c_str());
        printf("error_condition/gen: %s\n", econd_gen.message().c_str());
        printf("error_code/sys -> cond: (%d/%s) %s\n", ecodecond_sys.value(),
               ecodecond_sys.category().name(), ecodecond_sys.message().c_str());
        printf("error_code/gen -> cond: (%d/%s) %s\n", ecodecond_gen.value(),
               ecodecond_gen.category().name(), ecodecond_gen.message().c_str());
    }
    return 0;
}