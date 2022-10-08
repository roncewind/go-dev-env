ARG BASE_IMAGE=golang:1.19-bullseye
FROM $BASE_IMAGE

# Create the build image.

ARG SENZING_ACCEPT_EULA="I_ACCEPT_THE_SENZING_EULA"
ARG SENZING_APT_INSTALL_PACKAGE="senzingapi-runtime=3.3.0-22265"
ARG SENZING_APT_INSTALL_TOOLS_PACKAGE="senzingapi-tools=3.3.0-22265"
# ARG SENZING_APT_INSTALL_API_PACKAGE="senzingapi=3.3.0-22265"
# ARG SENZING_APT_INSTALL_DATA_PACKAGE="senzingdata-v3=3.0.0-22119"
ARG SENZING_APT_REPOSITORY_NAME="senzingrepo_1.0.1-1_amd64.deb"
ARG SENZING_APT_REPOSITORY_URL="https://senzing-production-apt.s3.amazonaws.com"
ARG SENZING_DATA_VERSION=3.0.0

ENV REFRESHED_AT=2022-09-15

ENV SENZING_ACCEPT_EULA=${SENZING_ACCEPT_EULA} \
    SENZING_APT_INSTALL_PACKAGE=${SENZING_APT_INSTALL_PACKAGE} \
    SENZING_APT_INSTALL_TOOLS_PACKAGE=${SENZING_APT_INSTALL_TOOLS_PACKAGE} \
#     SENZING_APT_INSTALL_API_PACKAGE=${SENZING_APT_INSTALL_API_PACKAGE} \
#     SENZING_APT_INSTALL_DATA_PACKAGE=${SENZING_APT_INSTALL_DATA_PACKAGE} \
    SENZING_APT_REPOSITORY_NAME=${SENZING_APT_REPOSITORY_NAME} \
    SENZING_APT_REPOSITORY_URL=${SENZING_APT_REPOSITORY_URL}

LABEL Name="roncewind/go-dev-env" \
      Maintainer="dad@lynntribe.com" \
      Version="0.0.0"

# Run as "root" for system installation.

USER root

# Install packages via apt.

RUN apt-get update \
 && apt-get -y install \
        wget

# Install Senzing repository index.

RUN wget -qO \
        /${SENZING_APT_REPOSITORY_NAME} \
        ${SENZING_APT_REPOSITORY_URL}/${SENZING_APT_REPOSITORY_NAME} \
 && apt-get -y install \
        /${SENZING_APT_REPOSITORY_NAME} \
 && apt-get update \
 && rm /${SENZING_APT_REPOSITORY_NAME}

# download and install binary openssl packages for libssl1.1 required by senzing
# RUN wget http://archive.ubuntu.com/ubuntu/pool/main/o/openssl/libssl1.1_1.1.0g-2ubuntu4_amd64.deb \
#  && dpkg -i ./libssl1.1_1.1.0g-2ubuntu4_amd64.deb \
#  && rm -rf ./libssl1.1_1.1.0g-2ubuntu4_amd64.deb

# Install Senzing package.

RUN apt-get -y install \
      libpq5 \
      python3-psycopg2 \
      ${SENZING_APT_INSTALL_PACKAGE} \
      ${SENZING_APT_INSTALL_TOOLS_PACKAGE} \
#       ${SENZING_APT_INSTALL_API_PACKAGE} \
#       ${SENZING_APT_INSTALL_DATA_PACKAGE} \
#  && mv /opt/senzing/data/${SENZING_DATA_VERSION}/* /opt/senzing/data/ \
#  && rm -rf /opt/senzing/data/${SENZING_DATA_VERSION} \
#  && rm -rf /opt/senzing/data/current \
#  && rm -rf /etc/alternatives/senzingdata \
 && rm -rf /var/lib/apt/lists/*

# Copy files from repository.

COPY ./rootfs /
# COPY ./senzing-examples/python /home/${NB_USER}/senzing-examples
# COPY ./senzing-tutorials /home/${NB_USER}/senzing-tutorials
# RUN rmdir /home/${NB_USER}/work \
#  && fix-permissions "/home/${NB_USER}" \
#  && fix-permissions "/var/opt/senzing"

# set permissions on the default database

RUN chmod -R 777 /var/opt/senzing/

# switch to the jupyter labs user

# USER $NB_UID

# Set environment variables for $NB_UID.

ENV LANGUAGE=C \
    LC_ALL=C.UTF-8 \
    LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/opt/senzing/g2/lib \
    PATH=${PATH}:/opt/senzing/g2/python \
    PYTHONPATH=${PYTHONPATH}/opt/senzing/g2/python:/opt/senzing/g2/sdk/python \
    PYTHONUNBUFFERED=1 \
    SENZING_DOCKER_LAUNCHED=true \
    SENZING_ENGINE_CONFIGURATION_JSON='{ \
       "PIPELINE": { \
              "CONFIGPATH": "/etc/opt/senzing", \
              "SUPPORTPATH": "/opt/senzing/data", \
              "RESOURCEPATH": "/opt/senzing/g2/resources" \
       }, \
       "SQL": { \
              "CONNECTION": "sqlite3://na:na@/var/opt/senzing/sqlite/G2C.db" \
       } \
    }' \
    SENZING_SKIP_DATABASE_PERFORMANCE_TEST=true \
    SENZING_TOOLS_DATABASE_URL="sqlite3://na:na@/var/opt/senzing/sqlite/G2C.db"
