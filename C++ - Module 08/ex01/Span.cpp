#include "Span.hpp"

Span::Span(unsigned int N)
	: N(N), a(), _shortestSpan(-1), _longestSpan(-1) {}

Span::~Span() {}

void Span::addNumber(int x) {
	if ((unsigned int)a.size() == N) {
		throw Span::FullSpan();
	}
	a.push_back(x);
	if (a.size() >= 2) {
		int local_span = a[a.size()-1] - a[a.size()-2];
		if (local_span < 0) local_span = -1;
		_shortestSpan = _shortestSpan==-1? local_span: std::min(_shortestSpan, local_span);
		_longestSpan = _longestSpan==-1? local_span: std::max(_longestSpan, local_span);
	}
}

int Span::shortestSpan() const {
	if (_shortestSpan == -1) {
		throw Span::NoSpan();
	}
	return _shortestSpan;
}

int Span::longestSpan() const {
	if (_longestSpan == -1) {
		throw Span::NoSpan();
	}
	return _longestSpan;
}

void Span::insert(Span::itt begin, Span::itt end) {
	if ((unsigned int)a.size() + end - begin > N) {
		throw Span::FullSpan();
	}
	while (begin != end) {
		addNumber(*begin++);
	}
}

const char * Span::FullSpan::what(void) const throw() {
	return "Full Span !";
}

const char * Span::NoSpan::what(void) const throw() {
	return "No Span !";
}