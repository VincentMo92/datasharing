/*
 *  This file is auto generated by oeedger8r. DO NOT EDIT.
 */
#include "helloworld_t.h"
#include <openenclave/edger8r/enclave.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

OE_EXTERNC_BEGIN



/****** ECALL function wrappers  *************/
void ecall_enclave_helloworld(
        uint8_t* input_buffer, size_t input_buffer_size,
        uint8_t* output_buffer, size_t output_buffer_size,
        size_t* output_bytes_written)
{
    oe_result_t _result = OE_FAILURE;

    /* Prepare parameters */
    enclave_helloworld_args_t* pargs_in = (enclave_helloworld_args_t*) input_buffer;
    enclave_helloworld_args_t* pargs_out = (enclave_helloworld_args_t*) output_buffer;

    size_t input_buffer_offset = 0;
    size_t output_buffer_offset = 0;
    OE_ADD_SIZE(input_buffer_offset, sizeof(*pargs_in));
    OE_ADD_SIZE(output_buffer_offset, sizeof(*pargs_out));

    /* Make sure input and output buffers lie within the enclave */
    if (!input_buffer || !oe_is_within_enclave(input_buffer, input_buffer_size))
        goto done;

    if (!output_buffer || !oe_is_within_enclave(output_buffer, output_buffer_size))
        goto done;

    /* Set in and in-out pointers */

    /* Set out and in-out pointers. In-out parameters are copied to output buffer. */

    /* lfence after checks */
    oe_lfence();

    /* Call user function */
    enclave_helloworld(
        );

    /* Success. */
    _result = OE_OK; 
    *output_bytes_written = output_buffer_offset;

done:
    if (pargs_out && output_buffer_size >= sizeof(*pargs_out)) 
        pargs_out->_result = _result;
}



/****** ECALL function table  *************/
oe_ecall_func_t __oe_ecalls_table[] = {
    (oe_ecall_func_t) ecall_enclave_helloworld,
};

size_t __oe_ecalls_table_size = OE_COUNTOF(__oe_ecalls_table);


/* ocall wrappers */

oe_result_t host_helloworld(
        )
{
    oe_result_t _result = OE_FAILURE;

    /* Marshaling struct */ 
    host_helloworld_args_t _args, *_pargs_in = NULL, *_pargs_out=NULL;

    /* Marshaling buffer and sizes */ 
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Fill marshaling struct */
    memset(&_args, 0, sizeof(_args));

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(host_helloworld_args_t));

    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(host_helloworld_args_t));

    /* Allocate marshaling buffer */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);

    _buffer = (uint8_t*) oe_allocate_ocall_buffer(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL) { 
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }

    /* Serialize buffer inputs (in and in-out parameters) */
    *(uint8_t**)&_pargs_in = _input_buffer; 
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));


    /* Copy args structure (now filled) to input buffer */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    /* Call host function */
    if((_result = oe_call_host_function(
                        fcn_id_host_helloworld,
                        _input_buffer, _input_buffer_size,
                        _output_buffer, _output_buffer_size,
                         &_output_bytes_written)) != OE_OK)
        goto done;

    /* Set up output arg struct pointer*/
    *(uint8_t**)&_pargs_out = _output_buffer; 
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));

    /* Check if the call succeeded */
    if ((_result=_pargs_out->_result) != OE_OK)
        goto done;

    /* Currently exactly _output_buffer_size bytes must be written */
    if (_output_bytes_written != _output_buffer_size) {
        _result = OE_FAILURE;
        goto done;
    }

    /* Unmarshal return value and out, in-out parameters */

    _result = OE_OK;
done:    
    if (_buffer)
        oe_free_ocall_buffer(_buffer);
    return _result;
}


OE_ECALL void _dummy_old_style_ecall_to_keep_loader_happy(void* arg){}

OE_EXTERNC_END
