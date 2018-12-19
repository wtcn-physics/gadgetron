#include "readers/GadgetIsmrmrdReader.h"
#include "DependencyQueryWriter.h"
#include "GadgetContainerMessage.h"

#include "io/writers.h"

namespace Gadgetron{

    void DependencyQueryWriter::serialize(std::ostream &stream, std::unique_ptr<DependencyQuery::Dependency> ptr) {
        using namespace Core;

        IO::write(stream,GADGET_MESSAGE_DEPENDENCY_QUERY);


        auto& meta = ptr->dependencies;

        std::stringstream meta_stream;
        ISMRMRD::serialize(meta,meta_stream);
        auto meta_string = meta_stream.str();

        IO::write(stream,meta_string.size());
        stream.write(meta_string.c_str(),meta_string.size()+1);

    }


    GADGETRON_WRITER_EXPORT(DependencyQueryWriter)
}
