#include <gtest/gtest.h>

#include <shogun/lib/NGramTokenizer.h>
#include <shogun/lib/SGVector.h>

using namespace shogun;

TEST(NGramTokenizerTest, tokenization)
{
	const char* text = "This is the ultimate test!";
	SGVector<char> cv(const_cast<char* >(text), 26, false);

	int32_t n = 3;
	auto tokenizer = std::make_shared<NGramTokenizer>(n);
	tokenizer->set_text(cv);

	index_t token_start = 0;
	int ngram_index = 0;
	while (tokenizer->has_next())
	{
		index_t token_end = tokenizer->next_token_idx(token_start);
		ASSERT_EQ(token_end-token_start, n);
		for (index_t i=0; i<n; i++)
		{
			ASSERT_EQ(text[ngram_index+i], text[token_start+i]);
		}
		ngram_index++;
	}

	
}
