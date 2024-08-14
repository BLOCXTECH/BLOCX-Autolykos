#include "includes.h"

void HeaderSerializer::serializeWithoutPow(const HeaderWithoutPow& h, Writer& w) {
    w.put(h.version);
    w.putBytes(idToBytes(h.parentId));
    w.putBytes(h.ADProofsRoot.data(), h.ADProofsRoot.size());
    w.putBytes(h.transactionsRoot.data(), h.transactionsRoot.size());
    w.putBytes(h.stateRoot.data(), h.stateRoot.size());
    w.putULong(h.timestamp);
    w.putBytes(h.extensionRoot.data(), h.extensionRoot.size());
    serialize(h.nBits, w); //DifficultySerializer
    w.putUInt(h.height);
    w.putBytes(h.votes.data(), h.votes.size());

    // For block version >= 2, this new byte encodes length of possible new fields.
    // Set to 0 for now, so no new fields.
    if (h.version > Header::InitialVersion) {
        w.putUByte(0);
    }
}

std::vector<uint8_t> HeaderSerializer::bytesWithoutPow(const HeaderWithoutPow& header) {
    Writer w;
    serializeWithoutPow(header, w);
    return w.result();
}

void HeaderSerializer::Serialize(const Header& h, Writer& w) {
    HeaderWithoutPow header(h.version, h.parentId, h.ADProofsRoot, h.stateRoot, h.transactionsRoot, h.timestamp, h.nBits, h.height, h.extensionRoot, h.votes);
    AutolykosSolutionSerializer SolutionSerializer;

    serializeWithoutPow(header, w);
    SolutionSerializer.serialize(h.version, h.powSolution, w);
}

std::vector<uint8_t> HeaderSerializer::toBytes(const Header& obj) {
    Writer writer;
    Serialize(obj, writer);
    return writer.result();
}
