FROM phusion/baseimage:bionic-1.0.0
LABEL maintainer="BLOCX_TESTNET Developers <dev@blocx_testnet.org>"
LABEL description="Dockerised BLOCX_TESTNETCore, built from Travis"

ARG USER_ID
ARG GROUP_ID

ENV HOME /home/blocx_testnet

# add user with specified (or default) user/group ids
ENV USER_ID ${USER_ID:-1000}
ENV GROUP_ID ${GROUP_ID:-1000}
RUN groupadd -g ${GROUP_ID} blocx_testnet && \
    useradd -u ${USER_ID} -g blocx_testnet -s /bin/bash -m -d /home/blocx_testnet blocx_testnet && \
    mkdir /home/blocx_testnet/.blocx_testnetcore && \
    chown ${USER_ID}:${GROUP_ID} -R /home/blocx_testnet

COPY bin/* /usr/local/bin/

RUN chmod a+x /usr/local/bin/*

USER blocx_testnet

VOLUME ["/home/blocx_testnet"]

EXPOSE 13971 13972 19998 19999

WORKDIR /home/blocx_testnet
