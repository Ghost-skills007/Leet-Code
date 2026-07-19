class Solution:
    def get_canonical_form(self, text: str) -> str:
        length = len(text)
        if length == 0:
            return ""
        
        doubled_text = text + text
        idx1, idx2, match_len = 0, 1, 0
        
        while idx1 < length and idx2 < length and match_len < length:
            if doubled_text[idx1 + match_len] == doubled_text[idx2 + match_len]:
                match_len += 1
            elif doubled_text[idx1 + match_len] > doubled_text[idx2 + match_len]:
                idx1 += match_len + 1
                if idx1 <= idx2:
                    idx1 = idx2 + 1
                match_len = 0
            else:
                idx2 += match_len + 1
                if idx2 <= idx1:
                    idx2 = idx1 + 1
                match_len = 0
                
        start_pos = min(idx1, idx2)
        return doubled_text[start_pos : start_pos + length]

    def minimumGroups(self, words: list[str]) -> int:
        unique_patterns = set()

        for word in words:
            even_chars = []
            odd_chars = []
            
            for index, char in enumerate(word):
                if index % 2 == 0:
                    even_chars.append(char)
                else:
                    odd_chars.append(char)
            
            even_str = "".join(even_chars)
            odd_str = "".join(odd_chars)
            
            group_key = f"{self.get_canonical_form(even_str)}#{self.get_canonical_form(odd_str)}"
            unique_patterns.add(group_key)

        return len(unique_patterns)