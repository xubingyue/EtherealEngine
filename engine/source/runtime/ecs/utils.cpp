#include "utils.h"
#include "core/serialization/serialization.h"
#include "core/serialization/archives.h"
#include "../Meta/Ecs/Entity.hpp"
#include "../assets/asset_extensions.h"

namespace ecs
{
	namespace utils
	{
		void save_entity(const fs::path& dir, const runtime::Entity& data)
		{
			const fs::path fullPath = dir / fs::path(data.to_string() + extensions::prefab);
			save_data(fullPath, { data });
		}

		bool try_load_entity(const fs::path& fullPath, runtime::Entity& outData)
		{
			std::vector<runtime::Entity> outDataVec;
			if (!load_data(fullPath, outDataVec))
				return false;

			if (!outDataVec.empty())
				outData = outDataVec[0];

			return true;
		}


		void save_data(const fs::path& fullPath, const std::vector<runtime::Entity>& data)
		{
			std::ofstream os(fullPath, std::fstream::binary | std::fstream::trunc);
			serialize_data(os, data);
		}

		bool load_data(const fs::path& fullPath, std::vector<runtime::Entity>& outData)
		{
			std::ifstream is(fullPath, std::fstream::binary);
			return deserialize_data(is, outData);
		}

		void serialize_data(std::ostream& stream, const std::vector<runtime::Entity>& data)
		{
			cereal::oarchive_json_t ar(stream);

			try_save(ar, cereal::make_nvp("data", data));

			getSerializationMap().clear();
		}

		bool deserialize_data(std::istream& stream, std::vector<runtime::Entity>& outData)
		{
			// get length of file:
			getSerializationMap().clear();
			stream.seekg(0, stream.end);
			std::streampos length = stream.tellg();
			stream.seekg(0, stream.beg);
			if (length > 0)
			{
				cereal::iarchive_json_t ar(stream);

				try_load(ar, cereal::make_nvp("data", outData));

				stream.clear();
				stream.seekg(0);
				getSerializationMap().clear();
				return true;
			}
			return false;
		}
	}
}
