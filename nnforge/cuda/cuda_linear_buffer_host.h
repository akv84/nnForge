/*
 *  Copyright 2011-2013 Maxim Milakov
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#pragma once

#include "cuda_linear_buffer.h"

#include <cuda_runtime.h>

namespace nnforge
{
	namespace cuda
	{
		class cuda_linear_buffer_host : public cuda_linear_buffer
		{
		public:
			cuda_linear_buffer_host(
				size_t size,
				unsigned int flags = cudaHostAllocDefault);

			virtual ~cuda_linear_buffer_host();

			virtual size_t get_size() const;

		protected:
			virtual void * get_buf();
			virtual const void * get_buf() const;

		private:
			void * buf;
			size_t size;
		};

		typedef nnforge_shared_ptr<cuda_linear_buffer_host> cuda_linear_buffer_host_smart_ptr;
		typedef nnforge_shared_ptr<const cuda_linear_buffer_host> const_cuda_linear_buffer_host_smart_ptr;
	}
}
