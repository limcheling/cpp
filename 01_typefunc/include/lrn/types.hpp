#include <string>
#include <cstring>
#include <type_traits>

namespace lrn {

template<typename Type>
std::string type_to_string(){
        std::string fname(__PRETTY_FUNCTION__);
        
        const char * with_type = "Type = ";
        auto pos = fname.find(with_type);
        fname = fname.substr(pos + std::strlen(with_type));

        
        return fname.substr(0, fname.find(";"));
}

template<typename ArrayType, auto ArraySize>
auto array_size(ArrayType( & )[ArraySize]) {
        return ArraySize;
}

}//end of namespace lrn
