#pragma once
enum class CellType : wchar_t
{
	EMPTY = (wchar_t)' ',
	SNAKE_BODY = (wchar_t)'O',
	SNAKE_HEAD = (wchar_t)'@',
	FOOD = (wchar_t)'%',
	BORDER = (wchar_t)'.'
};