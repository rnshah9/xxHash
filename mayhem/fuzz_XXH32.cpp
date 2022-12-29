#include <stdint.h>
#include <stdio.h>
#include <climits>

#include <fuzzer/FuzzedDataProvider.h>

#include "xxhash.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider provider(data, size);
    std::vector<uint8_t> vec = provider.ConsumeBytes<uint8_t>(100);
    uint32_t seed = provider.ConsumeIntegral<uint32_t>();

    XXH32(&vec[0], 100, seed);

    return 0;
}
