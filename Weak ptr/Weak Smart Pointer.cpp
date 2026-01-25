#include <iostream>
#include <memory>
#include <vector>

using namespace std;

// WEAK POINTER GUIDE:
// Purpose: Non-owning reference to an object managed by shared_ptr
// Use when:
// - Breaking circular references (parent-child, node graphs)
// - Caching systems (don't keep objects alive just for caching)
// - Observer patterns (observers shouldn't control subject lifetime)
// - Temporary access to shared objects without ownership

// Key Characteristics:
// - DOES NOT increase reference count
// - CANNOT access object directly - must convert to shared_ptr first
// - Automatically becomes empty when all shared_ptrs are destroyed
// - Safe against dangling pointers

class Resource
{
public:
    string name;

    Resource(const string& n) : name(n)
    {
        cout << "Resource '" << name << "' created\n";
    }

    ~Resource()
    {
        cout << "Resource '" << name << "' destroyed\n";
    }

    void use()
    {
        cout << "Using resource '" << name << "'\n";
    }
};

// ========== VARIABLES WITH WEAK_PTR ==========

void basic_variables_weak_ptr()
{
    cout << "=== BASIC VARIABLES WITH weak_ptr ===\n";

    // ✅ Step 1: Always create shared_ptr first
    shared_ptr<int> sharedInt = make_shared<int>(42);
    shared_ptr<double> sharedDouble = make_shared<double>(3.14159);
    shared_ptr<string> sharedString = make_shared<string>("Hello World");

    // ✅ Step 2: Create weak_ptr from shared_ptr
    weak_ptr<int> weakInt = sharedInt;
    weak_ptr<double> weakDouble = sharedDouble;
    weak_ptr<string> weakString = sharedString;

    cout << "After weak_ptr creation:\n";
    cout << "sharedInt use count: " << sharedInt.use_count() << "\n"; // Still 1!
    cout << "sharedDouble use count: " << sharedDouble.use_count() << "\n";

    // ✅ Accessing variables through weak_ptr
    cout << "\n--- Accessing Variables ---\n";

    // Method 1: Using lock() - SAFE
    if (auto lockedInt = weakInt.lock())
    {
        cout << "Integer value: " << *lockedInt << "\n";
        *lockedInt = 100; // Can modify through locked shared_ptr
        cout << "Modified integer: " << *lockedInt << "\n";
    }

    // Method 2: Check expired() first
    if (!weakDouble.expired())
    {
        auto lockedDouble = weakDouble.lock();
        cout << "Double value: " << *lockedDouble << "\n";
        *lockedDouble = 2.71828;
    }

    // Method 3: Direct lock and use
    if (auto lockedString = weakString.lock())
    {
        cout << "String value: " << *lockedString << "\n";
        *lockedString = "Modified through weak_ptr";
        cout << "Modified string: " << *lockedString << "\n";
    }

    // ✅ What happens when shared_ptr is destroyed
    cout << "\n--- Testing Lifetime ---\n";
    {
        auto tempShared = make_shared<int>(999);
        weak_ptr<int> tempWeak = tempShared;

        cout << "Before destruction - expired: " << tempWeak.expired() << "\n";
        if (auto locked = tempWeak.lock())
        {
            cout << "Value: " << *locked << "\n";
        }
    } // tempShared destroyed here

    // weak_ptr automatically knows the object is gone
    weak_ptr<int> deadWeak;
    {
        auto temp = make_shared<int>(123);
        deadWeak = temp;
    }
    cout << "After destruction - expired: " << deadWeak.expired() << "\n";
    if (!deadWeak.lock())
    {
        cout << "Correctly detected object destruction\n";
    }
}

// ========== ARRAYS WITH WEAK_PTR ==========

void arrays_with_weak_ptr()
{
    cout << "\n=== ARRAYS WITH weak_ptr ===\n";

    // ✅ 1D Arrays with weak_ptr
    cout << "--- 1D Arrays ---\n";

    // Create shared_ptr to array (with custom deleter for C++14 compatibility)
    shared_ptr<int[]> sharedArray(new int[5], [](int* p)
    {
        delete[] p;
    });

    // Initialize array
    for (int i = 0; i < 5; i++)
    {
        sharedArray[i] = i * 10;
    }

    // Create weak_ptr to the array
    weak_ptr<int[]> weakArray = sharedArray;

    cout << "Original array: ";
    for (int i = 0; i < 5; i++)
    {
        cout << sharedArray[i] << " ";
    }
    cout << "\n";

    // ✅ Access array elements through weak_ptr
    if (auto lockedArray = weakArray.lock())
    {
        cout << "Accessed through weak_ptr: ";
        for (int i = 0; i < 5; i++)
        {
            cout << lockedArray[i] << " ";
            lockedArray[i] *= 2; // Can modify!
        }
        cout << "\n";
    }

    // Check the original array was modified
    cout << "After modification: ";
    for (int i = 0; i < 5; i++)
    {
        cout << sharedArray[i] << " ";
    }
    cout << "\n";

    // ✅ 2D Arrays with weak_ptr
    cout << "\n--- 2D Arrays ---\n";

    const int ROWS = 3, COLS = 4;

    // Create 2D array as array of shared_ptrs
    shared_ptr<shared_ptr<int>[]> shared2D(new shared_ptr<int>[ROWS]);
    for (int i = 0; i < ROWS; i++)
    {
        shared2D[i] = shared_ptr<int>(new int[COLS], [](int* p)
        {
            delete[] p;
        });
        for (int j = 0; j < COLS; j++)
        {
            shared2D[i].get()[j] = i * 10 + j;
        }
    }

    // Create weak_ptr to 2D array
    weak_ptr<shared_ptr<int>[]> weak2D = shared2D;

    // Access 2D array through weak_ptr
    if (auto locked2D = weak2D.lock())
    {
        cout << "2D Array through weak_ptr:\n";
        for (int i = 0; i < ROWS; i++)
        {
            int* row = locked2D[i].get();
            for (int j = 0; j < COLS; j++)
            {
                cout << row[j] << "\t";
            }
            cout << "\n";
        }
    }
}

// ========== VECTORS WITH WEAK_PTR ==========

void vectors_with_weak_ptr()
{
    cout << "\n=== VECTORS WITH weak_ptr ===\n";

    // ✅ Vector of shared_ptrs with weak_ptr references
    auto sharedVec = make_shared<vector<int>>();
    sharedVec->push_back(10);
    sharedVec->push_back(20);
    sharedVec->push_back(30);

    weak_ptr<vector<int>> weakVec = sharedVec;

    if (auto lockedVec = weakVec.lock())
    {
        cout << "Vector contents: ";
        for (int val : *lockedVec)
        {
            cout << val << " ";
        }
        cout << "\n";

        // Can modify through weak_ptr
        lockedVec->push_back(40);
        cout << "After modification: ";
        for (int val : *lockedVec)
        {
            cout << val << " ";
        }
        cout << "\n";
    }
}

// ========== PRACTICAL ARRAY CACHING EXAMPLE ==========

class ArrayCache
{
private:
    vector<weak_ptr<int[]>> cache;

public:
    shared_ptr<int[]> getArray(const string& key, size_t size)
    {
        // Clean expired cache entries
        cache.erase(
            remove_if(cache.begin(), cache.end(),
                      [](const weak_ptr<int[]>& wp)
        {
            return wp.expired();
        }),
        cache.end()
        );

        // For demo - always create new, but in real cache you'd lookup by key
        auto newArray = shared_ptr<int[]>(new int[size], [](int* p)
        {
            delete[] p;
        });

        // Initialize with demo data
        for (size_t i = 0; i < size; i++)
        {
            newArray[i] = static_cast<int>(i * stoi(key));
        }

        cache.push_back(newArray);
        return newArray;
    }

    void printCacheStatus()
    {
        int valid = 0, expired = 0;
        for (const auto& weakArr : cache)
        {
            if (weakArr.expired()) expired++;
            else valid++;
        }
        cout << "Cache: " << valid << " valid, " << expired << " expired entries\n";
    }
};

void array_caching_demo()
{
    cout << "\n=== ARRAY CACHING WITH weak_ptr ===\n";

    ArrayCache cache;

    // Get some arrays
    auto arr1 = cache.getArray("10", 5);
    auto arr2 = cache.getArray("20", 3);

    cout << "Array 1: ";
    for (int i = 0; i < 5; i++) cout << arr1[i] << " ";
    cout << "\n";

    cache.printCacheStatus();

    // Release one array
    arr1.reset();
    cout << "After releasing arr1:\n";
    cache.printCacheStatus();
}

// ========== COMMON PATTERNS FOR VARIABLES & ARRAYS ==========

void variable_array_patterns()
{
    cout << "\n=== VARIABLE & ARRAY PATTERNS ===\n";

    // Pattern 1: Temporary calculation with arrays
    {
        auto dataArray = make_shared<int[]>(5);
        weak_ptr<int[]> dataWeak = dataArray;

        // Initialize
        for (int i = 0; i < 5; i++) dataArray[i] = i;

        // Pass weak reference to function that might not always need the data
        if (auto locked = dataWeak.lock())
        {
            int sum = 0;
            for (int i = 0; i < 5; i++) sum += locked[i];
            cout << "Array sum: " << sum << "\n";
        }
    }

    // Pattern 2: Configuration data that might be reloaded
    {
        struct Config
        {
            int timeout;
            string name;
        };

        auto currentConfig = make_shared<Config>(Config{30, "Server"});
        weak_ptr<Config> configWeak = currentConfig;

        // Some part of code that needs config but shouldn't keep it alive
        if (auto config = configWeak.lock())
        {
            cout << "Config: " << config->name << ", timeout: " << config->timeout << "\n";
        }
    }

    // Pattern 3: Large data arrays with multiple readers
    {
        auto largeData = make_shared<vector<double>>(1000, 3.14);
        weak_ptr<vector<double>> dataWeak = largeData;

        // Multiple components can check if data exists without forcing it to stay alive
        if (auto data = dataWeak.lock())
        {
            cout << "Data available, size: " << data->size() << "\n";
            // Process data...
        }
        else
        {
            cout << "Data no longer available, skip processing\n";
        }
    }
}

// ========== BEST PRACTICES FOR VARIABLES & ARRAYS ==========

void best_practices_variables_arrays()
{
    cout << "\n=== BEST PRACTICES: VARIABLES & ARRAYS ===\n";

    // ✅ GOOD: Create shared_ptr first, then weak_ptr
    auto sharedVar = make_shared<int>(42);
    weak_ptr<int> weakVar = sharedVar;

    // ✅ GOOD: Always check with lock() before accessing arrays
    auto sharedArr = shared_ptr<int[]>(new int[5], [](int* p)
    {
        delete[] p;
    });
    weak_ptr<int[]> weakArr = sharedArr;

    if (auto lockedArr = weakArr.lock())
    {
        for (int i = 0; i < 5; i++)
        {
            lockedArr[i] = i; // Safe access
        }
    }

    // ❌ BAD: Don't assume the array still exists
    // weakArr[0] = 10; // COMPILE ERROR - can't access directly

    // ✅ GOOD: Use weak_ptr for optional configuration
    weak_ptr<int[]> optionalConfig;
    {
        auto config = shared_ptr<int[]>(new int[3], [](int* p)
        {
            delete[] p;
        });
        optionalConfig = config;
    } // config destroyed

    if (auto config = optionalConfig.lock())
    {
        cout << "Config exists\n";
    }
    else
    {
        cout << "Config not available - use defaults\n";
    }

    // ✅ GOOD: weak_ptr for cache entries
    vector<weak_ptr<int[]>> arrayCache;
    auto cachedArray = shared_ptr<int[]>(new int[10], [](int* p)
    {
        delete[] p;
    });
    arrayCache.push_back(cachedArray);

    // Later: clean up expired cache entries
    arrayCache.erase(
        remove_if(arrayCache.begin(), arrayCache.end(),
                  [](const weak_ptr<int[]>& wp)
    {
        return wp.expired();
    }),
    arrayCache.end()
    );
}



/*
// Constructor - weak_ptr MUST be created from a shared_ptr
WeakPtrClassManual(const shared_ptr<int>& shared_data, const string& n) : data(shared_data), name(n)
{
    cout << "WeakPtrClassManual '" << name << "' constructed\n";
    print_status();
}
*/


/*
// MANUAL COPY CONSTRUCTOR
WeakPtrClassManual(const WeakPtrClassManual& other) : data(other.data),  name(other.name + "_manual_copy") // Copy the weak_ptr observation
{
    cout << "MANUAL WeakPtrClass COPY constructor called for '" << name << "'\n";
    cout << "Copied weak_ptr from '" << other.name << "' to '" << name << "'\n";
    print_status();
}
*/

/*
// MANUAL COPY ASSIGNMENT
WeakPtrClassManual& operator=(const WeakPtrClassManual& other)
{
    cout << "MANUAL WeakPtrClass COPY assignment called\n";

    if (this != &other)    // Self-assignment check
    {
        // Copy the weak_ptr observation (doesn't affect reference count)
        data = other.data;
        name = other.name + "_manual_assigned";

        cout << "After manual copy assignment:\n";
        cout << "  From: '" << other.name << "' to '" << name << "'\n";
        print_status();
    }
    else
    {
        cout << "Self-assignment detected - no operation needed\n";
    }
    return *this;
}
*/


/*
// MANUAL MOVE CONSTRUCTOR
WeakPtrClassManual(WeakPtrClassManual&& other) noexcept : data(move(other.data)),  name(move(other.name) + "_manual_moved") // Move the weak_ptr observation
{
    cout << "MANUAL WeakPtrClass MOVE constructor called for '" << name << "'\n";
    cout << "Moved weak_ptr from '" << other.name << "' to '" << name << "'\n";
    print_status();

    // After move, other.data is in valid but unspecified state
    // (usually empty, but not guaranteed)
}
*/


/*
// MANUAL MOVE ASSIGNMENT
WeakPtrClassManual& operator=(WeakPtrClassManual&& other) noexcept
{
    cout << "MANUAL WeakPtrClass MOVE assignment called\n";

    if (this != &other)
    {
        // Move the weak_ptr observation
        data = move(other.data);
        name = move(other.name) + "_manual_move_assigned";

        cout << "After manual move assignment:\n";
        cout << "  From: '" << other.name << "' to '" << name << "'\n";
        print_status();
    }
    else
    {
        cout << "Self-assignment detected in move - no operation needed\n";
    }
    return *this;
}
*/


/*
// Destructor
~WeakPtrClassManual()
{
    cout << "WeakPtrClassManual '" << name << "' destroyed - expired: " << data.expired() << "\n";
}
*/





int main()
{
    cout << "========== WEAK_PTR COMPREHENSIVE GUIDE ==========\n";

    basic_variables_weak_ptr();
    arrays_with_weak_ptr();
    vectors_with_weak_ptr();
    array_caching_demo();
    variable_array_patterns();
    best_practices_variables_arrays();

    cout << "\n========== VARIABLES & ARRAYS SUMMARY ==========\n";
    cout << "✓ weak_ptr works with any type: int, double, string, arrays, vectors\n";
    cout << "✓ ALWAYS create shared_ptr first, then weak_ptr from it\n";
    cout << "✓ For arrays: use custom deleters or C++17 make_shared<int[]>\n";
    cout << "✓ Access arrays through locked shared_ptr: weakArr.lock()[i]\n";
    cout << "✓ Perfect for caching large arrays and configuration data\n";

    return 0;
}
