

#include <iostream>

#include <milo/inner.h>
#include <milo/literal.h>

#include <milo/crypto/cipher/chacha.h>
#include <milo/crypto/cipher/test.h>


using namespace milo::literal;

struct test_vector
{
    const size_t id;
    
    const milo::container::chars_const_view_dynamic key;
    
    const milo::container::chars_const_view_dynamic iv;
    
    const milo::container::chars_const_view_dynamic plaintext;
    
    const milo::container::chars_const_view_dynamic ciphertext;
};

constexpr milo::container::array<test_vector, 3> test_vectors
    {
        test_vector
            {
                .id = 1,
                .key =
                "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
                "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"_cv,
                .iv =
                "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"_cv,
                .plaintext =
                "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
                "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
                "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
                "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"_cv,
                .ciphertext =
                "\x76\xb8\xe0\xad\xa0\xf1\x3d\x90\x40\x5d\x6a\xe5\x53\x86\xbd\x28"
                "\xbd\xd2\x19\xb8\xa0\x8d\xed\x1a\xa8\x36\xef\xcc\x8b\x77\x0d\xc7"
                "\xda\x41\x59\x7c\x51\x57\x48\x8d\x77\x24\xe0\x3f\xb8\xd8\x4a\x37"
                "\x6a\x43\xb8\xf4\x15\x18\xa1\x1c\xc3\x87\xb6\x69\xb2\xee\x65\x86"_cv
            },
        test_vector
            {
                .id = 2,
                .key =
                "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
                "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01"_cv,
                .iv =
                "\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x02"_cv,
                .plaintext =
                "\x41\x6e\x79\x20\x73\x75\x62\x6d\x69\x73\x73\x69\x6f\x6e\x20\x74"
                "\x6f\x20\x74\x68\x65\x20\x49\x45\x54\x46\x20\x69\x6e\x74\x65\x6e"
                "\x64\x65\x64\x20\x62\x79\x20\x74\x68\x65\x20\x43\x6f\x6e\x74\x72"
                "\x69\x62\x75\x74\x6f\x72\x20\x66\x6f\x72\x20\x70\x75\x62\x6c\x69"
                "\x63\x61\x74\x69\x6f\x6e\x20\x61\x73\x20\x61\x6c\x6c\x20\x6f\x72"
                "\x20\x70\x61\x72\x74\x20\x6f\x66\x20\x61\x6e\x20\x49\x45\x54\x46"
                "\x20\x49\x6e\x74\x65\x72\x6e\x65\x74\x2d\x44\x72\x61\x66\x74\x20"
                "\x6f\x72\x20\x52\x46\x43\x20\x61\x6e\x64\x20\x61\x6e\x79\x20\x73"
                "\x74\x61\x74\x65\x6d\x65\x6e\x74\x20\x6d\x61\x64\x65\x20\x77\x69"
                "\x74\x68\x69\x6e\x20\x74\x68\x65\x20\x63\x6f\x6e\x74\x65\x78\x74"
                "\x20\x6f\x66\x20\x61\x6e\x20\x49\x45\x54\x46\x20\x61\x63\x74\x69"
                "\x76\x69\x74\x79\x20\x69\x73\x20\x63\x6f\x6e\x73\x69\x64\x65\x72"
                "\x65\x64\x20\x61\x6e\x20\x22\x49\x45\x54\x46\x20\x43\x6f\x6e\x74"
                "\x72\x69\x62\x75\x74\x69\x6f\x6e\x22\x2e\x20\x53\x75\x63\x68\x20"
                "\x73\x74\x61\x74\x65\x6d\x65\x6e\x74\x73\x20\x69\x6e\x63\x6c\x75"
                "\x64\x65\x20\x6f\x72\x61\x6c\x20\x73\x74\x61\x74\x65\x6d\x65\x6e"
                "\x74\x73\x20\x69\x6e\x20\x49\x45\x54\x46\x20\x73\x65\x73\x73\x69"
                "\x6f\x6e\x73\x2c\x20\x61\x73\x20\x77\x65\x6c\x6c\x20\x61\x73\x20"
                "\x77\x72\x69\x74\x74\x65\x6e\x20\x61\x6e\x64\x20\x65\x6c\x65\x63"
                "\x74\x72\x6f\x6e\x69\x63\x20\x63\x6f\x6d\x6d\x75\x6e\x69\x63\x61"
                "\x74\x69\x6f\x6e\x73\x20\x6d\x61\x64\x65\x20\x61\x74\x20\x61\x6e"
                "\x79\x20\x74\x69\x6d\x65\x20\x6f\x72\x20\x70\x6c\x61\x63\x65\x2c"
                "\x20\x77\x68\x69\x63\x68\x20\x61\x72\x65\x20\x61\x64\x64\x72\x65"
                "\x73\x73\x65\x64\x20\x74\x6f"_cv,
                .ciphertext =
                "\xa3\xfb\xf0\x7d\xf3\xfa\x2f\xde\x4f\x37\x6c\xa2\x3e\x82\x73\x70"
                "\x41\x60\x5d\x9f\x4f\x4f\x57\xbd\x8c\xff\x2c\x1d\x4b\x79\x55\xec"
                "\x2a\x97\x94\x8b\xd3\x72\x29\x15\xc8\xf3\xd3\x37\xf7\xd3\x70\x05"
                "\x0e\x9e\x96\xd6\x47\xb7\xc3\x9f\x56\xe0\x31\xca\x5e\xb6\x25\x0d"
                "\x40\x42\xe0\x27\x85\xec\xec\xfa\x4b\x4b\xb5\xe8\xea\xd0\x44\x0e"
                "\x20\xb6\xe8\xdb\x09\xd8\x81\xa7\xc6\x13\x2f\x42\x0e\x52\x79\x50"
                "\x42\xbd\xfa\x77\x73\xd8\xa9\x05\x14\x47\xb3\x29\x1c\xe1\x41\x1c"
                "\x68\x04\x65\x55\x2a\xa6\xc4\x05\xb7\x76\x4d\x5e\x87\xbe\xa8\x5a"
                "\xd0\x0f\x84\x49\xed\x8f\x72\xd0\xd6\x62\xab\x05\x26\x91\xca\x66"
                "\x42\x4b\xc8\x6d\x2d\xf8\x0e\xa4\x1f\x43\xab\xf9\x37\xd3\x25\x9d"
                "\xc4\xb2\xd0\xdf\xb4\x8a\x6c\x91\x39\xdd\xd7\xf7\x69\x66\xe9\x28"
                "\xe6\x35\x55\x3b\xa7\x6c\x5c\x87\x9d\x7b\x35\xd4\x9e\xb2\xe6\x2b"
                "\x08\x71\xcd\xac\x63\x89\x39\xe2\x5e\x8a\x1e\x0e\xf9\xd5\x28\x0f"
                "\xa8\xca\x32\x8b\x35\x1c\x3c\x76\x59\x89\xcb\xcf\x3d\xaa\x8b\x6c"
                "\xcc\x3a\xaf\x9f\x39\x79\xc9\x2b\x37\x20\xfc\x88\xdc\x95\xed\x84"
                "\xa1\xbe\x05\x9c\x64\x99\xb9\xfd\xa2\x36\xe7\xe8\x18\xb0\x4b\x0b"
                "\xc3\x9c\x1e\x87\x6b\x19\x3b\xfe\x55\x69\x75\x3f\x88\x12\x8c\xc0"
                "\x8a\xaa\x9b\x63\xd1\xa1\x6f\x80\xef\x25\x54\xd7\x18\x9c\x41\x1f"
                "\x58\x69\xca\x52\xc5\xb8\x3f\xa3\x6f\xf2\x16\xb9\xc1\xd3\x00\x62"
                "\xbe\xbc\xfd\x2d\xc5\xbc\xe0\x91\x19\x34\xfd\xa7\x9a\x86\xf6\xe6"
                "\x98\xce\xd7\x59\xc3\xff\x9b\x64\x77\x33\x8f\x3d\xa4\xf9\xcd\x85"
                "\x14\xea\x99\x82\xcc\xaf\xb3\x41\xb2\x38\x4d\xd9\x02\xf3\xd1\xab"
                "\x7a\xc6\x1d\xd2\x9c\x6f\x21\xba\x5b\x86\x2f\x37\x30\xe3\x7c\xfd"
                "\xc4\xfd\x80\x6c\x22\xf2\x21"_cv
            },
        test_vector
            {
                .id = 3,
                .key =
                "\x1c\x92\x40\xa5\xeb\x55\xd3\x8a\xf3\x33\x88\x86\x04\xf6\xb5\xf0"
                "\x47\x39\x17\xc1\x40\x2b\x80\x09\x9d\xca\x5c\xbc\x20\x70\x75\xc0"_cv,
                .iv =
                "\x2a\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x02"_cv,
                .plaintext =
                "\x27\x54\x77\x61\x73\x20\x62\x72\x69\x6c\x6c\x69\x67\x2c\x20\x61"
                "\x6e\x64\x20\x74\x68\x65\x20\x73\x6c\x69\x74\x68\x79\x20\x74\x6f"
                "\x76\x65\x73\x0a\x44\x69\x64\x20\x67\x79\x72\x65\x20\x61\x6e\x64"
                "\x20\x67\x69\x6d\x62\x6c\x65\x20\x69\x6e\x20\x74\x68\x65\x20\x77"
                "\x61\x62\x65\x3a\x0a\x41\x6c\x6c\x20\x6d\x69\x6d\x73\x79\x20\x77"
                "\x65\x72\x65\x20\x74\x68\x65\x20\x62\x6f\x72\x6f\x67\x6f\x76\x65"
                "\x73\x2c\x0a\x41\x6e\x64\x20\x74\x68\x65\x20\x6d\x6f\x6d\x65\x20"
                "\x72\x61\x74\x68\x73\x20\x6f\x75\x74\x67\x72\x61\x62\x65\x2e"_cv,
                .ciphertext =
                "\x62\xe6\x34\x7f\x95\xed\x87\xa4\x5f\xfa\xe7\x42\x6f\x27\xa1\xdf"
                "\x5f\xb6\x91\x10\x04\x4c\x0d\x73\x11\x8e\xff\xa9\x5b\x01\xe5\xcf"
                "\x16\x6d\x3d\xf2\xd7\x21\xca\xf9\xb2\x1e\x5f\xb1\x4c\x61\x68\x71"
                "\xfd\x84\xc5\x4f\x9d\x65\xb2\x83\x19\x6c\x7f\xe4\xf6\x05\x53\xeb"
                "\xf3\x9c\x64\x02\xc4\x22\x34\xe3\x2a\x35\x6b\x3e\x76\x43\x12\xa6"
                "\x1a\x55\x32\x05\x57\x16\xea\xd6\x96\x25\x68\xf8\x7d\x3f\x3f\x77"
                "\x04\xc6\xa8\xd1\xbc\xd1\xbf\x4d\x50\xd6\x15\x4b\x6d\xa7\x31\xb1"
                "\x87\xb5\x8d\xfd\x72\x8a\xfa\x36\x75\x7a\x79\x7a\xc1\x88\xd1"_cv
            },
    };

constexpr auto
test(
) noexcept(true) -> size_t
{
    size_t test_vectors_size = test_vectors.size();
    size_t test_vectors_failed = 0;
    
    for (size_t i = 0; i < test_vectors_size; i += 1)
    {
        auto result = milo::crypto::cipher::test<milo::crypto::cipher::chacha_20>::encrypt(
            test_vectors[i].key,
            test_vectors[i].iv,
            test_vectors[i].plaintext,
            test_vectors[i].ciphertext
        );
        
        if (result)
        {
            continue;
        }
        
        if MILO_CONSTEVAL
        {
            return test_vectors[i].id;
        }
        else
        {
            if (test_vectors_failed == 0)
            {
                std::cerr << "Tests that failed:\n";
            }
            
            std::cerr << "  - " << test_vectors[i].id << "\n";
        }
        
        test_vectors_failed += 1;
    }
    
    return test_vectors_failed;
}

auto
main(
) noexcept(false) -> int
{
    #ifdef MILO_TESTS_CONSTEXPR
    static_assert(test() == 0);
    #endif
    
    volatile auto test_cb = test;
    
    return test_cb() > 0;
}

